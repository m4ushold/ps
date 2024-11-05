#include <bits/stdc++.h>
using namespace std;

int N, K, Q[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    for(int i=1,a;i<=N;i++) {
        cin >> a;
        int f=1;
        for(int j=1;j<=K;j++) {
            if(Q[j] < a) {Q[j]=a, f=0; break;}
        }
        if(f) return cout << "NO", 0;
    }
    cout << "YES";
    return 0;
}