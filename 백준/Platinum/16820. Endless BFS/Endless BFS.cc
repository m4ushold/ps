#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

vector<int> G[202020];
int A[202020], B[202020], C[202020], AC, BC;

int dfs(int v=1, int p=-1) {
    int res=0;
    for(int i:G[v]) if(i!=p) {
        if(C[i] && C[i] == C[v]) return 1;
        else if(C[i]) continue;
        C[i] = C[v]==1 ? 2 : 1;
        res |= dfs(i,v);
    }
    return res;
}

void sol(int tc) {
    int n,m; cin >> n >> m;
    AC=BC=n;
    for(int i=0;i<m;i++) {
        int a,b; cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }
    C[1]=1;
    if(!dfs()) {
        cout << -1;
        return;
    }

    queue<int> a,b;
    a.push(1);
    A[1]=1;
    AC--;
    int cnt=0;
    while(AC && BC) {
        if(cnt&1) {
            while(b.size()) {
                int v = b.front(); b.pop();
                for(int i:G[v]) {
                    if(A[i]==0) {
                        A[i] = 1;
                        AC--;
                        a.push(i);
                    }
                }
            }
        } else {
            while(a.size()) {
                int v = a.front(); a.pop();
                for(int i:G[v]) {
                    if(B[i]==0) {
                        B[i] = 1;
                        BC--;
                        b.push(i);
                    }
                }
            }
        }
        cnt++;
    }
    cout << cnt << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}