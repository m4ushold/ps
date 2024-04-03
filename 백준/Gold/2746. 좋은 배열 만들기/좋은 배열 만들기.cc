#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, A[505050], C[1010101];
ll P[505050];

ll f(ll x) { return min(max(x,0LL),(ll)1e6+1); }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i], C[A[i]]++;
    sort(A+1,A+N+1);
    vector<int> v, a;
    for(int i=1;i<=N;i++) {
        P[i]=P[i-1]+A[i];
        if(A[i-1]!=A[i]) v.emplace_back(A[i]);
    }
    int t=3;
    while(t-- && !v.empty()) a.push_back(v.back()), v.pop_back();

    ll cnt=0, sum=P[N];
    for(int i=1,j;i<=N;i++) {
        for(auto v:a) {
            j=f(sum-v*2-A[i]);
            if((v!=A[i] && v!=j) || C[v]>1 && C[v]) cnt+= C[j] - (A[i]==j);
        }
    }

    cout << cnt/2;

    return 0;
}