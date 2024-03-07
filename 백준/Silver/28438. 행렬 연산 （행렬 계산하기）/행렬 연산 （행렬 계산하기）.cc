#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, Q, A[505050], B[505050];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;
    while(Q--) {
        int o,a,b; cin >> o >> a >> b;
        if(o&1) A[a]+=b;
        else B[a]+=b;
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) cout << A[i]+B[j] << ' ';
        cout << '\n';
    }
    return 0;
}