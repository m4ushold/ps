#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> h({1,2,3,3,4,10}), s({1,2,2,2,3,5,10});
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        int hh=0, ss=0;
        for(int i=0,a;i<6;i++) cin >> a, hh+=a*h[i];
        for(int i=0,a;i<7;i++) cin >> a, ss+=a*s[i];

        cout << "Battle " << i << ": ";
        if(hh>ss) cout << "Good triumphs over Evil\n";
        else if(hh<ss) cout << "Evil eradicates all trace of Good\n";
        else cout << "No victor on this battle field\n";
    }
    
    return 0;
}