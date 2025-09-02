#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, IN[101], IIN[101], A[101];
vector<int> G[101];

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        int x; cin >> x;
        IN[i]=IIN[i]=x;
        while(x--) {
            int p; cin >> p;
            G[p].push_back(i);
        }
    }

    ll a=0, b=0, flag=0;
    vector<int> aa, bb;
    queue<int> q[2];
    for(int i=1;i<=N;i++) if(!IN[i]) q[A[i]].push(i);
    while(q[0].size() || q[1].size()) {
        if(q[flag].size() == 0) flag^=1, a++;
        int v = q[flag].front(); q[flag].pop();
        aa.push_back(v);
        for(int i:G[v]) if(--IN[i] == 0) {
            q[A[i]].push(i);
        }
    }
    for(int i=1;i<=N;i++) {
        if((IN[i] = IIN[i]) == 0) q[A[i]].push(i);
    }
    flag=1;
    while(q[0].size() || q[1].size()) {
        if(q[flag].size() == 0) flag^=1, b++;
        int v = q[flag].front(); q[flag].pop();
        bb.push_back(v);
        for(int i:G[v]) if(--IN[i] == 0) {
            q[A[i]].push(i);
        }
    }
    if(a>b) swap(a,b), swap(aa,bb);

    cout << a << '\n';
    for(int i:aa) cout << i << ' ';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}