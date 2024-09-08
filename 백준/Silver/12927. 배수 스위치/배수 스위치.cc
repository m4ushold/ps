#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    s='#'+s;
    int n=s.size(), cnt=0;
    for(int i=1;i<n;i++) {
        if(s[i]=='Y') {
            for(int j=i;j<n;j+=i) s[j]=s[j]=='Y'?'N':'Y';
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}