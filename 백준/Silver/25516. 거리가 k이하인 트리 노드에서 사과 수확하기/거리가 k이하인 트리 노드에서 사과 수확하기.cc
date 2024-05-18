#include <bits/stdc++.h>
using namespace std;

int A[101010], K;
vector<int> T[101010];

int dfs(int v=0, int d=-1) {
    if(d==K) return 0;
    int ret=0;
    for(int i:T[v]) ret+=dfs(i,d+1);
    return ret+A[v];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n >> K;
    for(int i=1,p,c;i<n;i++) cin >> p >> c, T[p].push_back(c);
    for(int i=0;i<n;i++) cin >> A[i];
    cout << dfs();
    return 0;
}