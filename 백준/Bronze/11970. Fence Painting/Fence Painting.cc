#include <bits/stdc++.h>
using namespace std;

int A[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,b,c,d; cin >> a >> b >> c >> d;
    for(int i=a;i<b;i++) A[i]=1;
    for(int i=c;i<d;i++) A[i]=1;
    cout << accumulate(A, A+101, 0);
    return 0;
}