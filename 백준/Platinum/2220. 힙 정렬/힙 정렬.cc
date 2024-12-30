#include <bits/stdc++.h>
using namespace std;

int N, H[1<<17];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) {
        H[i]=i;
        if(i>1) swap(H[i-1], H[i]);
        int t=i-1;
        while(t>1 && H[t] > H[t/2]) swap(H[t], H[t/2]), t/=2;
    }
    for(int i=1;i<=N;i++) cout << H[i] << ' ';
    return 0;
}