#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, A[101010];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int mx=0, cnt=0;
    for(int i=1,a;i<=N*2;i++) {
        cin >> a;
        if(!A[a]) A[a]=1, cnt++;
        else A[a]=0, cnt--;
        mx=max(mx,cnt);
    }
    cout << mx;
    return 0;
}