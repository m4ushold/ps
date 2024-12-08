#include <bits/stdc++.h>
using namespace std;

int f(string s, char a) {
    for(char c:s) if(c==a) return 1;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int cnt=0;
    for(int t=0;t<(n+1)*60*60;t++) {
        string h=to_string(t/60/60), m=to_string(t/60%60), s=to_string(t%60);
        if(h.size()<2) h='0'+h;
        if(m.size()<2) m='0'+m;
        if(s.size()<2) s='0'+s;
        string tt=h+m+s;
        if(f(tt,k+48)) cnt++;
    }
    cout << cnt;
    return 0;
}