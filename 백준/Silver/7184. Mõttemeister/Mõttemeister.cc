#include <bits/stdc++.h>
using namespace std;

pair<int, int> ab(const string &s, const string &t) {
    int a=0,b=0;
    for(int i=0;i<4;i++) b+=s[i]==t[i];
    for(int i=0;i<10;i++) {
        int aa=0,bb=0;
        for(char c:s) aa+=c-48==i;
        for(char c:t) bb+=c-48==i;
        a+=min(aa,bb);
    }
    return {a,b};
}

bool chk(const string &s, const string &t, int a, int b) {
    auto [aa, bb] = ab(s, t);
    return aa==a && bb==b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<tuple<string,int,int>> v(n);
    for(auto &[i,j,k]:v) cin >> i >> j >> k;
    vector<string> dap;
    for(int i=0;i<10'000;i++) {
        string num = to_string(i);
        while(num.size()<4) num="0"+num;
        int f=1;
        for(auto [s,a,b]:v) {
            if(!chk(num,s,a,b)) {
                f=0;
                break;
            }
        }
        if(f) dap.push_back(num);
    }
    cout << dap.size() << '\n';
    sort(dap.begin(),dap.end());
    for(auto i:dap) cout << i << '\n';
    return 0;
}