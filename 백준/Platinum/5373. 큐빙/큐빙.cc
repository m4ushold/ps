#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Cube=vector<vector<vector<int>>>;
using pos=tuple<int,int,int>;

vector<char> c={'w','y','r','o','g','b'};
Cube cube; // u,d,f,b,l,r

void init()
{
    cube=Cube(6);
    for(int i=0;i<6;i++) {
        cube[i]=vector<vector<int>>(3);
        for(int j=0;j<3;j++) {
            cube[i][j]=vector<int>(3);
            for(int k=0;k<3;k++) cube[i][j][k]=i;
        }
    }
}

void rotate(vector<pos> v, pos p)
{
    auto [a,b,c]=p;
    for(auto [x,y,z]:v) {
        swap(cube[x][y][z],cube[a][b][c]);
        a=x, b=y, c=z;
    }
}

void print();

void r(int i,bool p)
{
    vector<pos> v={{i,0,1},{i,0,2},{i,1,2},{i,2,2},{i,2,1},{i,2,0},{i,1,0}};
    if(p) reverse(v.begin(),v.end());
    for(int j=0;j<2;j++) rotate(v,{i,0,0});
}

void U(bool p)
{
    r(0,p);
    vector<pos> v={{2,0,1},{2,0,2},{5,0,0},{5,0,1},{5,0,2},{3,0,0},{3,0,1},{3,0,2},{4,0,0},{4,0,1},{4,0,2}};
    if(!p) reverse(v.begin(),v.end());
    for(int i=0;i<3;i++) rotate(v,{2,0,0});
}

void D(bool p)
{
    r(1,p);
    vector<pos> v={{2,2,1},{2,2,2},{5,2,0},{5,2,1},{5,2,2},{3,2,0},{3,2,1},{3,2,2},{4,2,0},{4,2,1},{4,2,2}};
    if(p) reverse(v.begin(),v.end());
    for(int i=0;i<3;i++) rotate(v,{2,2,0});
}

void F(bool p)
{
    r(2,p);
    vector<pos> v={{0,2,1},{0,2,2},{5,0,0},{5,1,0},{5,2,0},{1,0,2},{1,0,1},{1,0,0},{4,2,2},{4,1,2},{4,0,2}};
    if(p) reverse(v.begin(),v.end());
    for(int i=0;i<3;i++) rotate(v,{0,2,0});
}

void B(bool p)
{
    r(3,p);
    vector<pos> v={{0,0,1},{0,0,2},{5,0,2},{5,1,2},{5,2,2},{1,2,2},{1,2,1},{1,2,0},{4,2,0},{4,1,0},{4,0,0}};
    if(!p) reverse(v.begin(),v.end());
    for(int i=0;i<3;i++) rotate(v,{0,0,0});
}

void L(bool p)
{
    r(4,p);
    vector<pos> v={{0,1,0},{0,2,0},{2,0,0},{2,1,0},{2,2,0},{1,0,0},{1,1,0},{1,2,0},{3,2,2},{3,1,2},{3,0,2}};
    if(p) reverse(v.begin(),v.end());
    for(int i=0;i<3;i++) rotate(v,{0,0,0});
}

void R(bool p)
{
    r(5,p);
    vector<pos> v={{0,1,2},{0,2,2},{2,0,2},{2,1,2},{2,2,2},{1,0,2},{1,1,2},{1,2,2},{3,2,0},{3,1,0},{3,0,0}};
    if(!p) reverse(v.begin(),v.end());
    for(int i=0;i<3;i++) rotate(v,{0,0,2});
}

void rotate(string s)
{
    if(s[0]=='U') U(s[1]=='+');
    else if(s[0]=='D') D(s[1]=='+');
    else if(s[0]=='F') F(s[1]=='+');
    else if(s[0]=='B') B(s[1]=='+');
    else if(s[0]=='L') L(s[1]=='+');
    else if(s[0]=='R') R(s[1]=='+');
}

void print()
{
    for(auto i:cube[0]) {
        for(int j:i) cout << c[j];
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        init();
        int n; cin >> n;
        while(n--) {
            string s; cin >> s;
            rotate(s);
        }
        print();
    }
    return 0;
}