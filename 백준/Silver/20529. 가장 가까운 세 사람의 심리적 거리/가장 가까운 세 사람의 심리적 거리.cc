#include <bits/stdc++.h>
using namespace std;

int f(string s) { return ((s[0]=='E')<<3) + ((s[1]=='N')<<2) + ((s[2]=='T')<<1) + (s[3]=='J'); }
int c(int a, int b) {return __popcount(a^b);}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s;
        vector<int> m(16), v;
        while(n--) cin >> s, ++m[f(s)];
        for(int i=0;i<16;i++) for(int j=0;j<min(m[i],3);j++) v.push_back(i);
        int mn=1e9;
        for(int i=0;i<v.size();i++) for(int j=i+1;j<v.size();j++) for(int k=j+1;k<v.size();k++) mn=min(mn,c(v[i],v[j])+c(v[j],v[k])+c(v[i],v[k]));
        cout << mn << '\n';
    }
    return 0;
}