#include <bits/stdc++.h>
using namespace std;
using ll=long long;

char A[5][5], B[5][5];

bool bound(int x, int y) {return 0<=min(x,y) && max(x,y)<5;}

int dfs(int v, int dep=0) {
    if(dep==7) return 0;
    int res=1;
    B[v/5][v%5]=0;
    int x=v/5, y=v%5;
    for(auto [i,j]:vector<pair<int,int>>({{1,0},{0,1},{-1,0},{0,-1}})) if(bound(x+i,y+j) && B[x+i][y+j]==1) {
        res+=dfs((x+i)*5+y+j, dep+1);
    }
    return res;
}

bool chk(const vector<int> &v) {
    memset(B, 0, sizeof(B));
    int cnt=0, n=v.size(), a;
    for(int i=0;i<25;i++) if(v[i]) cnt+=A[i/5][i%5]=='S', a=i, B[i/5][i%5]=1;
    return dfs(a)==7 && cnt>3;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) cin >> A[i][j];

    vector<int> v(25);
    for(int i=0;i<7;i++) v[i]=1;
    int cnt=0;
    do {
        cnt+=chk(v);
    } while(prev_permutation(v.begin(),v.end()));
    cout << cnt;
    return 0;
}