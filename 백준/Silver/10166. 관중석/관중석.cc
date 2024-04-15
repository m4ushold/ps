#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b; cin >> a >> b;
    int dap=0;
    for(int i=a;i<=b;i++) {
        int cnt=i-1;
        for(int j=a;j<i;j++) cnt-=gcd(j,i)-1;
        dap+=cnt;
    }
    cout << dap+1;
    return 0;
}