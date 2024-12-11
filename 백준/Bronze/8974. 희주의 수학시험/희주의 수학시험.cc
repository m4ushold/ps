#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[1010];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<=45;i++) {
        for(int j=1+i*(i-1)/2;j<=(i+1)*i/2 && j<1010;j++) A[j]=i;
    }
    int a,b; cin >> a >> b;
    ll s=0;
    for(int i=a;i<=b;i++) s+=A[i];
    cout << s;
    return 0;
}