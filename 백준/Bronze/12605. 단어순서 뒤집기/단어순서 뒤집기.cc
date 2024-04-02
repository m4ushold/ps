#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    cin.get();
    for(int i=1;i<=t;i++) {
        string s; getline(cin,s);
        vector<string> v;
        v.emplace_back();
        for(char c:s) {
            if(c==' ') v.emplace_back();
            else v.back()+=c;
        }
        reverse(v.begin(),v.end());
        cout << "Case #" << i << ": ";
        for(auto j:v) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}