#include <bits/stdc++.h>
using namespace std;

int f(int N, int n, int k) {
    string s;
    for(int i=N-1;i>=0;i--) s+=n&(1<<i) ? '1' : '0';
    char a = s[0];
    int cnt = 1;
    for(int i=1;i<N;i++) {
        if(s[i]==a) cnt++;
        else a=s[i], cnt=1;
        if(cnt>k) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    int cnt=0;
    for(int i=0;i<(1<<n);i++) cnt+=f(n,i,k);
    cout << cnt;
    return 0;
}