#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s,p,res; cin >> s >> p;
    for(char c:s) {
        res+=c;
        if(res.size() >= p.size() && res.substr(res.size()-p.size())==p) {
            for(int i=0;i<p.size();i++) res.pop_back();
        }
    }
    cout << (res.empty() ? "FRULA" : res);
    return 0;
}