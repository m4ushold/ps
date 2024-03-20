#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=20;
int A[1<<sz], F[1<<sz];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        memset(F,0,sizeof F);
        for(int i=1,a;i<=n;i++) cin >> A[i], F[A[i]]++;
        for(int i=0;i<sz;i++) for(int x=0;x<(1<<sz);x++){
            if(x&(1<<i)) F[x]+=F[x^(1<<i)];
        }

        ll res=0;
        for(int i=1;i<=n;i++) res+=F[A[i]];
        cout << res << '\n';
    }
    return 0;
}