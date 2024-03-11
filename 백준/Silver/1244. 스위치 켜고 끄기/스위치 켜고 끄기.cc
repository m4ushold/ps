#include <bits/stdc++.h>
using namespace std;

int N, Q, A[101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    cin >> Q;
    while(Q--) {
        int a,n; cin >> a >> n;
        if(a&1) for(int i=n;i<=N;i+=n) A[i]=!A[i];
        else {
            int l=n-1,r=n+1; A[n]=!A[n];
            while(0<l && r<=N && A[l]==A[r]) A[l]=!A[l], A[r]=!A[r], --l, ++r;
        }
    }
    for(int i=1;i<=N;i++) {
        cout << A[i] << ' ';
        if(i%20==0) cout << '\n';
    }
    return 0;
}