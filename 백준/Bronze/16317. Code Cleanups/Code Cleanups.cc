#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[505];

void sol(int tc) {
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i, A[i]=1;

    int s=0,cnt=0,ans=0;
    for(int i=1;i<505;i++) {
        s+=cnt;
        if(s >= 20) {
            s=0,cnt=0;
            ans++;
        }
        cnt+=A[i];
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}