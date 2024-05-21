#include <bits/stdc++.h>
using namespace std;

bool chk(string s) {
    int j=max_element(s.begin(),s.end()) - s.begin();
    if(j==0 || j==s.size()-1) return 0;
    for(int i=1;i<=j;i++) if(s[i-1]>=s[i]) return 0;
    for(int i=j+1;i<s.size();i++) if(s[i-1]<=s[i]) return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(1010101);
    for(int i=1;i<1010101;i++) v[i]=v[i-1]+chk(to_string(i));
    int t; cin >> t;
    while(t--) {
        int a,b; cin >> a >> b;
        cout << v[b]-v[a-1] << '\n';
    }
    return 0;
}