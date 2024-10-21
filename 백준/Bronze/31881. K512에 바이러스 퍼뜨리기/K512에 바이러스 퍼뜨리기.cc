#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, Q, A[202020];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    int ans=N;
    for(int i=1,op,x;i<=Q;i++) {
        cin >> op;
        if(op==1) {
            cin >> x;
            if(!A[x]) ans--, A[x]=1;
        } else if(op==2) {
            cin >> x;
            if(A[x]) ans++, A[x]=0;
        } else cout << ans << '\n';
    }
    return 0;
}