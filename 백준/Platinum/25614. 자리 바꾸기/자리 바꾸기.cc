#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, A[202020], B[202020], C[202020], MOD[202020];
vector<vector<int>> S;
string M;
set<int> MODS;

ll m(int p) {
    ll res=0;
    for(char c:M) res=(res*10+c-'0')%p;
    return res;
}

void calc() {
    for(int i=1;i<=N;i++) if(!C[i]) {
        int v=i, p=0;
        S.emplace_back();
        while(!C[v]) C[v]=1, S.back().push_back(v), v=A[v], p++;
        MODS.insert(p);
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    calc();
    for(ll i:MODS) MOD[i]=m(i);

    for(auto vec:S) {
        int p=vec.size();
        for(int j=0;j<p;j++) B[vec[j]]=vec[(j+MOD[p])%p];
    }
    for(int i=1;i<=N;i++) cout << B[i] << ' ';
    
    return 0;
}