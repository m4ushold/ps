#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a,b,c;
        char d,e;
        cin >> a >> d >> b >> e >> c;
        string f=bitset<6>(a).to_string(),g=bitset<6>(b).to_string(),h=bitset<6>(c).to_string();
        for(int i=0;i<6;i++) cout << f[i] << g[i] << h[i];
        cout << ' ';
        cout << f << g << h << '\n';
    }
    return 0;
}