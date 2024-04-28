#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a; cin >> a;
        a--, a%=28, a++;
        if(a>15) a=30-a;
        for(char c:bitset<4>(a).to_string()) cout << (c=='1' ? "딸기" : "V");
        cout << '\n';
    }
    return 0;
}