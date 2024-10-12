#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M;

int test(int l) {
    ll sum=l*(l-1)/2, s=1;
    if(N < sum) return -1;
    if((N-sum)%l==0) {
        return (N-sum)/l;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=M;i<=100;i++) {
        int a=test(i);
        if(a>=0) {
            for(int j=a;j<a+i;j++) cout << j << ' ';
            return 0;
        }
    }
    cout << -1;
    return 0;
}