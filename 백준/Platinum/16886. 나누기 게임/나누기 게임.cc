#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, D[101010];

int mex(set<int> &s) {
    int i=0;
    while(s.count(i)) i++;
    return i;
}

int f(int n, int k) {
    int s = k * (k - 1) / 2, a = (n - s) / k;
    if (a > 0 && (n - s) % k == 0) {
        return a;
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=3;i<=N;i++) {
        set<int> s;
        for(int k=2;k*(k+1)/2<=i;k++) {
            int a=f(i, k), b=a+k-1, d=0;
            if(a > 0) {
                for(int j=a;j<=b;j++) d^=D[j];
                s.insert(d);
            }
        }
        D[i]=mex(s);
    }

    if(D[N]) for(int k=2;k*(k+1)/2<=N;k++) {
        int a=f(N, k), b=a+k-1, d=0;
        if(a > 0) {
            for(int j=a;j<=b;j++) d^=D[j];
            if(!d) {cout << k; return 0;}
        }
    } else cout << -1;
    return 0;
}