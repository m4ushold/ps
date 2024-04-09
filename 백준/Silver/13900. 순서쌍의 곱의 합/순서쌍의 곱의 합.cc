#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll R, A[101010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for(int i=1,a;i<=n;i++) cin >> A[i], R+=A[i]*A[i-1], A[i]+=A[i-1];
    cout << R;
    return 0;
}