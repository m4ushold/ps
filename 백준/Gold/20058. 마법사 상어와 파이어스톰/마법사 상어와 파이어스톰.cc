#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, A[66][66], B[66][66], C[66][66];
vector<pair<int,int>> v({
    {1,0},{0,1},{-1,0},{0,-1}
});

bool chk(int x, int y) {return 1<=min(x,y) && max(x,y)<=(1<<N);}

void melt() {
    for(int i=1;i<=1<<N;i++) for(int j=1;j<=1<<N;j++) {
        int x=i,y=j,cnt=0;
        for(auto [dx,dy]:v) if(chk(x+dx,y+dy) && A[x+dx][y+dy]) cnt++;
        if(cnt<3 && A[i][j]) C[i][j]=A[i][j]-1;
        else C[i][j]=A[i][j];
    }
    for(int i=1;i<=1<<N;i++) for(int j=1;j<=1<<N;j++) A[i][j]=C[i][j];
}

void f(int l) {
    if(l<2) {
        melt();
        return;
    }
    
    int ll = l/2;
    for(int i=1;i<=1<<N;i+=l) for(int j=1;j<=1<<N;j+=l) {
        for(int k=i;k<i+l;k++) for(int m=j;m<j+l;m++) {
            if(k<i+ll && m<j+ll) { // 1 quad
                C[k][m+ll] = A[k][m];
            } else if(k<i+ll) { // 2 quad
                C[k+ll][m] = A[k][m];
            } else if(i+ll<=k && m<j+ll) { // 3 quad
                C[k-ll][m] = A[k][m];
            } else { // 4 quad
                C[k][m-ll] = A[k][m];
            }
        }
    }
    for(int i=1;i<=1<<N;i++) for(int j=1;j<=1<<N;j++) A[i][j]=C[i][j];
    f(l/2);
}

ll dfs(int x, int y) {
    ll res=1;
    B[x][y]=1;
    for(auto [dx,dy]:v) if(chk(x+dx,y+dy) && A[x+dx][y+dy] && !B[x+dx][y+dy]) res+=dfs(x+dx,y+dy);
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=1<<N;i++) for(int j=1;j<=1<<N;j++) cin >> A[i][j];
    for(int i=1,l;i<=Q;i++) cin >> l, f(1<<l);
    ll sum=0, mx=0;
    for(int i=1;i<=1<<N;i++) for(int j=1;j<=1<<N;j++) sum+=A[i][j];
    for(int i=1;i<=1<<N;i++) for(int j=1;j<=1<<N;j++) {
        if(!B[i][j] && A[i][j]) mx=max(mx,dfs(i,j));
    }
    cout << sum << '\n' << mx;
    return 0;
}