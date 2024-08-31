#include <bits/stdc++.h>
using namespace std;

char A[5][5], B[5][5], C;
vector<pair<int,int>> d({{1,0},{0,1},{-1,0},{0,-1}});

bool bound(int x, int y) {return 0<=min(x,y) && max(x,y)<5;}

int conn(int x, int y) {
    int ret=1;
    B[x][y]=0;
    for(auto [dx,dy]:d) if(bound(x+dx,y+dy) && B[x+dx][y+dy]) ret+=conn(x+dx,y+dy);
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<pair<int,int>> p;
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) {
        cin >> A[i][j];
        if(A[i][j]=='*') C++, p.push_back({i,j});
    }
    vector<int> v(25);
    for(int i=0;i<C;i++) v[i]=1;

    int dap=1e9;
    do {
        vector<pair<int,int>> q;
        for(int i=0;i<25;i++) {
            B[i/5][i%5]=v[i];
            if(v[i]) q.push_back({i/5,i%5});
        }
        if(conn(q[0].first, q[0].second)!=C) continue;
        
        // calc ans
        sort(q.begin(),q.end());
        do {
            int cnt=0;
            for(int i=0;i<C;i++) cnt+=abs(p[i].first-q[i].first)+abs(p[i].second-q[i].second);
            dap=min(dap, cnt);
        } while(next_permutation(q.begin(),q.end()));
    } while(prev_permutation(v.begin(),v.end()));
    cout << dap;
    return 0;
}