#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[11], S;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) {
        double x; cin >> x;
        int a = round(x*100);
        S += a/5*5;
        A[a%5]++;
    }
    // 3 4
    // 4 4 4
    // 3 3

    ll mn = min(A[3], A[4]);
    S += mn*5;
    A[3]-=mn, A[4]-=mn;

    S += A[4]/3*10;
    A[4]%=3;

    S += A[3]/2*5;
    A[3]%=2;
    
    S += A[3]*3 + A[4]*4;
    cout << S/100 << '.';
    if(S%100 < 10) cout << 0;
    cout << S%100;
    return 0;
}