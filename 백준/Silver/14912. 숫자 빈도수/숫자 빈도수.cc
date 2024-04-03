#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a,res=0; cin >> n >> a;
    for(int i=1;i<=n;i++) {
        for(char c:to_string(i)) if(c-'0'==a) res++;
    }
    cout << res;
    return 0;
}