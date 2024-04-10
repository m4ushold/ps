#include <bits/stdc++.h>
using namespace std;

int N, M, A[101010];

bool f(int x) {
    int a=0;
    for(int i=1;i<=M;i++) {
        if(a<A[i]-x) return 0;
        a=A[i]+x;
    }
    return a>=N;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=M;i++) cin >> A[i];

    int s=0,e=N;
    while(s<e) {
        int m=(s+e)/2;
        if(f(m)) e=m;
        else s=m+1;
    }
    cout << e;
    return 0;
}