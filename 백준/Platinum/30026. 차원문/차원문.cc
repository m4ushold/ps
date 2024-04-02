#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, P[202020];
pair<int,int> A[202020];

void Init(int n) { for(int i=1;i<=n;i++) P[i]=i;}
int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    Init(N);
    for(int i=1;i<=N;i++) cin >> A[i].first, A[i].second=i, Union(i,A[i].first);
    sort(A+1, A+N+1);
    
    vector<pair<int,int>> r;
    for(int i=1;i<N;i++) if(Union(A[i].first,A[i+1].first)) r.emplace_back(A[i].second,A[i+1].second), swap(A[i],A[i+1]);
    cout << r.size() << ' ' << r.size() << '\n';
    for(auto [a,b]:r) cout << a << ' ' << b << '\n';
    return 0;
}