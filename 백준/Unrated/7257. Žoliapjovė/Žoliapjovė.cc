#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MX=1'000'000;
ll N, A[1010101], M, B[1010101], L;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(ll i=1,a;i<=N;i++) cin >> a, A[a]++;
    for(ll i=1;i<=MX;i++) B[i]=B[i-1]+A[i]*i;
    for(ll i=1;i<=MX;i++) A[i]+=A[i-1];

    cin >> M;
    for(ll i=1,a;i<=M;i++) {
        ll b; cin >> b;
        L+=b-1;
        L=min(L,MX);
        cout << B[MX]-B[L]-L*(A[MX]-A[L]) << '\n';
    }

    return 0;
}