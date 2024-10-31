#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll P[505050], C[505050], S[505050], MX[505050];
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {
    u=Find(u), v=Find(v);
    if(u != v) {
        P[u]=v;
        S[v]+=S[u];
        C[v]+=C[u];
        return 1;
    }
    C[u]=1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    vector<int> t;
    
    ll sum=0;
    for(auto &[a,b]:v) cin >> a >> b, t.push_back(a), t.push_back(b), sum+=a+b;
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(),t.end()),t.end());
    for(int i=1;i<=t.size();i++) P[i]=i, S[i]=t[i-1];

    for(auto [a,b]:v) {
        a=lower_bound(t.begin(),t.end(),a)-t.begin()+1;
        b=lower_bound(t.begin(),t.end(),b)-t.begin()+1;
        Union(a,b);
    }
    for(int i=1;i<=t.size();i++) {
        int j=Find(i);
        MX[j]=max(MX[j], (ll)i);
    }
    for(int i=1;i<=t.size();i++) if(i==P[i]) sum-=S[i]-(C[i] ? 0 : t[MX[i]-1]);
    cout << sum;
    return 0;
}