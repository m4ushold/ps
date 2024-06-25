#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll A[1010101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p; cin >> n >> p;
    for(int i=n;i>=0;i--) cin >> A[i], A[i]%=p;
    cout << A[0] << '\n';
    for(int i=p;i<=n;i++) A[i%(p-1)]=(A[i%(p-1)]+A[i])%p;
    
    for(int i=1;i<p;i++) {
        ll dap=0;
        for(int j=0,e=1;j<p;j++,e=e*i%p) {
            dap=(dap+A[j]*e%p)%p;
        }
        cout << dap << '\n';
    }
    return 0;
}