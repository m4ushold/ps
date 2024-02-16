#include <bits/stdc++.h>
using namespace std;

int V[1010];
vector<int> G[1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        for(int i=0;i<1010;i++) G[i].clear(), V[i]=0;
        int n, m, k; cin >> n >> m >> k;
        for(int i=0,a,b;i<m;i++) cin >> a >> b, G[a].push_back(b), G[b].push_back(a);
        for(int i=0,a;i<k;i++) {
            cin >> a, V[a]=1;
            for(int j:G[a]) V[j]=1;
        }
        cout << accumulate(V, V+1010, 0) << "\n";
    }
    return 0;
}