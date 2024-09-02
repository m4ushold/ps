#include <bits/stdc++.h>
using namespace std;

int A[202020];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    if(~n&1) cout << n << " 1 " << n << " ", n--;
    else cout << "1 ";

    A[0]=1;
    for(int i=1;i<n;i+=2) A[i]=i+2;
    for(int i=2;i<n;i+=2) A[i]=i;
    
    reverse(A, A+n);
    for(int i=0;i<n;i++) cout << A[i] << ' ';
    reverse(A, A+n);
    for(int i=1;i<n;i++) cout << A[i] << ' ';
    
    return 0;
}