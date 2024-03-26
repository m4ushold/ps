#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, R, A[101010], B[101010], C[101010];
vector<int> V;
string M;

int mod(int p) {
    int res=0;
    for (char c:M) res=(res*10+(c-'0'))%p;
    return res;
}

int dfs(int v, int d=0) {
    if(C[v]) return d;
    V.push_back(v);
    C[v]=1;
    return dfs(A[v],d+1);
}

void f() {
    for(int i=1;i<=N;i++) B[i]=C[i]=0;

    for(int i=1;i<=N;i++) if(!C[i]) {
        int p=mod(dfs(i));
        for(int j=0;j<V.size();j++) B[V[j]]=V[(j+p)%V.size()];
        V.clear();
    }

    R=0;
    for(int i=1;i<=N;i++) R+=i*B[i];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i], R+=i*A[i];

    cin >> Q;
    while(Q--) {
        int a,b,c; cin >> a;
        if(a&1) cin >> b >> c, swap(A[b], A[c]);
        else f(), cout << R << '\n';
    }
    return 0;
}