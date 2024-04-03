#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n, cout << n << ' ';
        vector<int> v(20);
        for(int &i:v) cin >> i;
        int res=0;
        for(int i=0;i<20;i++) {            
            for(int j=0;j<i;j++) if(v[j]>v[i]) res++;
        }
        cout << res << '\n';
    }
    return 0;
}