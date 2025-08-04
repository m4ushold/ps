#include <bits/stdc++.h>
using namespace std;

constexpr int sz=1<<20;
int N, A[101010], S[sz], E[sz];
vector<pair<int,int>> G[sz];
vector<int> D[101010];

vector<pair<int,int>> f(int x) {
    map<int,int> m;
    while(x>1) {
        m[S[x]]++;
        x/=S[x];
    }
    return vector<pair<int,int>>(m.begin(),m.end());
}

void gen_divs(vector<pair<int,int>> &fac, vector<int> &res, int x=1, int idx=0) {
    if(idx==fac.size()) {
        res.push_back(x);
        return;
    }
    for(int i=0;i<=fac[idx].second;i++) {
        gen_divs(fac,res,x,idx+1);
        x*=fac[idx].first;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=2;i<sz;i++) {
        if(S[i]) continue;
        for(int j=i;j<sz;j+=i) {
            if(S[j]) continue;
            S[j]=i;
        }
    }
    for(int i=2;i<sz;i++) E[i]=E[i/S[i]]+1;
    
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        vector<pair<int,int>> fac = f(A[i]);
        gen_divs(fac, D[i]);
        for(int j:D[i]) G[j].push_back({E[A[i]]-2*E[j], i});
    }

    for(int i=1;i<sz;i++) sort(G[i].begin(),G[i].end());

    for(int i=1;i<=N;i++) {
        int mn=1e9, ans=1e9;
        for(int j:D[i]) {
            if(G[j].size() == 1 && G[j][0].second == i) continue;
            int k = G[j][0].second == i ? G[j][1].second : G[j][0].second;
            int tmp = E[A[i]]+E[A[k]]-E[j]*2;
            if(mn > tmp) mn=tmp, ans=k;
            else if(mn == tmp) ans=min(ans,k);
        }
        cout << ans << '\n';
    }
    return 0;
}