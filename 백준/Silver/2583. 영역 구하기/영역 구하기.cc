#include <bits/stdc++.h>
using namespace std;

int N, M, K, A[101][101];
vector<pair<int,int>> v({{1,0},{0,1},{-1,0},{0,-1}});

int f(int i, int j) {
    if(A[i][j]) return 0;
    A[i][j]=1;
    int res=1;
    for(auto [x,y]:v) if(0<=min(i+x,j+y) && i+x<N && j+y<M && !A[i+x][j+y]) res+=f(i+x,j+y);
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=0,a,b,c,d;i<K;i++) {
        cin >> a >> b >> c >> d;
        for(int i=b;i<d;i++) for(int j=a;j<c;j++) A[i][j]=1;
    }

    vector<int> dap;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(!A[i][j]) dap.push_back(f(i,j));

    sort(dap.begin(),dap.end());
    cout << dap.size() << '\n';
    for(int i:dap) cout << i << ' ';
    return 0;
}