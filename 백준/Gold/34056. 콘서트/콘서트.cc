#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, Q, A[202020];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    cin >> Q;
    for(int i=1;i<=Q;i++) {
        ll op,c,x;
        cin >> op >> c;
        if(op == 1) {
            cin >> x;
            ll tmp = x;
            for(int j=c;j && x;j--) {
                ll aa = min(x, A[j]);
                A[j]+=aa, x-=aa;
            }
            x=tmp;
            for(int j=c+1;j<=N && x;j++) {
                ll aa = min(x, A[j]);
                A[j]+=aa, x-=aa;
            }
        } else cout << A[c] << '\n';
    }
    return 0;
}