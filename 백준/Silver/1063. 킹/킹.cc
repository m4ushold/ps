#include <bits/stdc++.h>
using namespace std;
using ll=long long;

// R : 한 칸 오른쪽으로
// L : 한 칸 왼쪽으로
// B : 한 칸 아래로
// T : 한 칸 위로
// RT : 오른쪽 위 대각선으로
// LT : 왼쪽 위 대각선으로
// RB : 오른쪽 아래 대각선으로
// LB : 왼쪽 아래 대각선으로

bool chk(int x, int y) {return 1<=min(x,y) && max(x,y)<=8;}

pair<int,int> stoco(string s) {
    return {s[0]-'A'+1, s[1]-'0'};
}

string cotos(pair<int,int> p) {
    string res;
    res+=p.first+'A'-1;
    res+=p.second+'0';
    return res;
}

pair<int,int> move(string dir, pair<int,int> p) {
    int &x=p.first, &y=p.second;
    if(dir=="R") {
        if(chk(x+1,y)) x++;
    } else if(dir=="L") {
        if(chk(x-1,y)) x--;
    } else if(dir=="B") {
        if(chk(x,y-1)) y--;
    } else if(dir=="T") {
        if(chk(x,y+1)) y++;
    } else if(dir=="RT") {
        if(chk(x+1, y+1)) x++, y++;
    } else if(dir=="LT") {
        if(chk(x-1,y+1)) x--, y++;
    } else if(dir=="RB") {
        if(chk(x+1,y-1)) x++, y--;
    } else {
        if(chk(x-1,y-1)) x--, y--;
    }
    return p;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string king,stone; int n;
    cin >> king >> stone >> n;
    pair<int,int> k=stoco(king), s=stoco(stone);
    for(int i=0;i<n;i++) {
        string d; cin >> d;
        auto tmpk = move(d,k);
        if(tmpk==s) {
            if(move(d,s) != s) k=move(d, k), s=move(d,s);
        } else k=move(d,k);
    }
    cout << cotos(k) << '\n' << cotos(s);
    return 0;
}