#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b; cin >> a >> b;
    ll dap=a;
    for(int i=a+1;i<=b;i++) {
        set<int> s;
        s.insert(1);
        for(int j=a,g;j<i;j++) {
            g=gcd(i,j);
            if(g!=1) for(int k=g;k<i;k+=g) s.insert(k);
        }
        dap+=i-s.size();
    }
    cout << dap;
    return 0;
}