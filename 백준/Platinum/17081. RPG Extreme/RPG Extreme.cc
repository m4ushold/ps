#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

struct Monster {
    int r,c,atk,def,hp,exp,maxHp;
    string name;
};

struct Item {
    char type;
    int n;
    string effect;
};

struct Box {
    int r,c,opened; 
    Item item;
};

struct Player
{
    int hp,maxHp,atk,def,level,exp;
    set<string> effects;
    Item weapon, armor;
    Player() { hp=maxHp=20, atk=2, def=2, level=1, exp=0; }

    void levelUp() { level++, maxHp+=5, hp=maxHp, atk+=2, def+=2, exp=0; }
    void addEffect(string e) { effects.insert(e); }
    bool hasEffect(string e) { return effects.find(e)!=effects.end(); }

    void addExp(int d) {
        if(hasEffect("EX")) d=1.2*d;
        exp+=d;
        if(exp>=level*5) levelUp();
    }
};

int N, M, K, L, T;
char MAP[101][101];
string Command, CauseOfDeath;
Point SP, CurPos, BossPos;
map<Point,int> BoxIdx, MonsterIdx;
vector<Monster> monsters;
vector<Box> boxes;
Player player;

void move()
{
    Point nxt=CurPos;
    if(Command[T]=='L') nxt.second=max(1,CurPos.second-1);
    else if(Command[T]=='R') nxt.second=min(CurPos.second+1,M);
    else if(Command[T]=='U') nxt.first=max(1,CurPos.first-1);
    else if(Command[T]=='D') nxt.first=min(CurPos.first+1,N);
    if(MAP[nxt.first][nxt.second]!='#') CurPos=nxt;
}

void act()
{
    move();

    Box& box=boxes[BoxIdx[CurPos]];
    Monster &m=monsters[MonsterIdx[CurPos]];

    switch (MAP[CurPos.first][CurPos.second])
    {
    case 'B':
        box.opened=true;

        if(box.item.type=='W') player.weapon=box.item;
        else if(box.item.type=='A') player.armor=box.item;
        else if(player.effects.size()<4) player.addEffect(box.item.effect);
        
        MAP[CurPos.first][CurPos.second]='.';
        break;
        
    case '^':
        if(player.hasEffect("DX")) player.hp=max(player.hp-1,0);
        else player.hp=max(player.hp-5,0);
        
        if(!player.hp&&player.hasEffect("RE")) {
            player.hp=player.maxHp;
            CurPos=SP;
            player.effects.erase("RE");
        }

        if(!player.hp) CauseOfDeath="SPIKE TRAP";
        break;
    case '&':
    case 'M':
        if(CurPos==BossPos&&player.hasEffect("HU")) player.hp=player.maxHp;
        int pAtk=player.atk+player.weapon.n, pDef=player.def+player.armor.n, firstAtk=1;
        while(1) {
            if(firstAtk&&player.hasEffect("CO")) {
                if(player.hasEffect("DX")) m.hp=max(m.hp-max(1,pAtk*3-m.def),0);
                else m.hp=max(m.hp-max(1,pAtk*2-m.def),0);
            } else m.hp=max(m.hp-max(1,pAtk-m.def),0);
            if(!m.hp) break;

            if(!(CurPos==BossPos&&firstAtk&&player.hasEffect("HU"))) player.hp=max(0,player.hp-max(1,m.atk-pDef));
            if(!player.hp) break;
            firstAtk=0;
        }

        if(player.hp) {
            if(player.hasEffect("HR")) player.hp=min(player.maxHp,player.hp+3);
            player.addExp(m.exp);
        }
        
        if(!player.hp&&player.hasEffect("RE")) {
            m.hp=m.maxHp;
            player.hp=player.maxHp;
            CurPos=SP;
            player.effects.erase("RE");
        }

        if(!player.hp) CauseOfDeath=m.name;
        if(!m.hp) MAP[CurPos.first][CurPos.second]='.';
        break;
    }

    T++;
}

Monster Boss() { return monsters[MonsterIdx[BossPos]]; }

bool isFinished() { return T>=Command.size()||!player.hp||!Boss().hp; }

void input()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        cin >> MAP[i][j];
        if(MAP[i][j]=='M') K++, BossPos={i,j};
        if(MAP[i][j]=='&') K++;
        if(MAP[i][j]=='B') L++;
        if(MAP[i][j]=='@') CurPos=SP={i,j};
    }
    cin >> Command;

    int i=0;
    monsters.resize(K);
    for(Monster &m:monsters) {
        cin >> m.r >> m.c >> m.name >> m.atk >> m.def >> m.maxHp >> m.exp;
        m.hp=m.maxHp;
        MonsterIdx[{m.r,m.c}]=i++;
    }

    i=0;
    boxes.resize(L);
    for(Box &b:boxes) {
        cin >> b.r >> b.c >> b.item.type;
        BoxIdx[{b.r,b.c}]=i++;
        if(b.item.type=='O') cin >> b.item.effect;
        else cin >> b.item.n;
    }
}

void print()
{
    MAP[SP.first][SP.second]='.';
    if(player.hp) MAP[CurPos.first][CurPos.second]='@';
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) cout << MAP[i][j];
        cout << '\n';
    }
    cout << "Passed Turns : " << T << '\n';
    cout << "LV : " << player.level << '\n';
    cout << "HP : " << player.hp << "/" << player.maxHp << '\n';
    cout << "ATT : " << player.atk << "+" << player.weapon.n << '\n';
    cout << "DEF : " << player.def << "+" << player.armor.n << '\n';
    cout << "EXP : " << player.exp << "/" << player.level*5 << '\n';
    if(!Boss().hp) cout << "YOU WIN!\n";
    else if(!player.hp) cout << "YOU HAVE BEEN KILLED BY " << CauseOfDeath << "..\n";
    else cout << "Press any key to continue.\n"; 
}

int main()
{
    input();
    while(!isFinished()) act();
    print();
    return 0;
}