#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAX_V=202;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];

bool dfs(int v)  {
    vi[v]=1;
    for(int i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

bool chk(ll a, ll b) {
    ll c=hypot(a,b);
    for(ll i=c-1;i<=c+1;i++) if(i*i==a*a+b*b) return 1;
    return 0;
}

int matching() {
    int cnt=0;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=0;i<MAX_V;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    vector<int> v(N);
    for(int &i:v) cin >> i;
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        if(gcd(v[i],v[j])==1 && chk(v[i],v[j])) {
            if(v[i]&1) G[i].push_back(j);
            else G[j].push_back(i);
        }
    }
    cout << matching();
    return 0;
}