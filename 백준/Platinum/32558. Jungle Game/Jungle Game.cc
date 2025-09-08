#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, A[101010], B[101010], AA[101010], BB[101010], C[101010];

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> A[i] >> B[i], AA[A[i]]++, BB[B[i]]++;
        C[A[i]]=B[i];
    }

    for(int i=1;i<=N;i++) if(!AA[i+i]) {
        cout << "YES\n";
        for(int j=1;j<=N;j++) cout << i << ' ' << j << '\n';
        return;
    }

    for(int i=1;i<=N;i++) if(!BB[i+i]) {
        cout << "YES\n";
        for(int j=1;j<=N;j++) cout << j << ' ' << i << '\n';
        return;
    }

    if(N==1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int x=0;
    for(int i=1;i<=N;i++) if(B[i] == 2) x=A[i]/2;
    for(int i=2;i<=N;i++) cout << x << ' ' << i << '\n';

    for(int i=(x&1 ? 2 : 1);i<=N;i+=2) {
        if(C[i+i] != 2) {
            cout << i << ' ' << 1;
            return;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}