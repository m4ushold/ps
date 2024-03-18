#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, A[404040];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> A[i], A[i+N]=A[i];
    for(int i=1;i<=2*N;i++) A[i]+=A[i-1];

    int l=0;
    for(int i=0,q,a,b;i<Q;i++) {
        cin >> q >> a;
        if(q==1) l=(l-a+N)%N;
        else if(q==2) l=(l+a)%N;
        else cin >> b, cout << A[b+l]-A[a+l-1] << '\n';
    }

    return 0;
}