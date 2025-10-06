#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, IN[55];
char A[55][55];
vector<int> G[55];

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j];
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(A[i][j] == 'Y' && A[j][i] == 'N') G[i].push_back(j), IN[j]++;
    }

    queue<int> q;
    for(int i=1;i<=N;i++) if(!IN[i]) q.push(i);
    while(q.size()) {
        int v = q.front(); q.pop();
        for(int i:G[v]) if(--IN[i] == 0) {
            q.push(i);
        }
    }

    for(int i=1;i<=N;i++) if(IN[i]) {
        cout << "NO";
        return;
    }
    cout << "YES";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}