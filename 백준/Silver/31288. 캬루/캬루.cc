#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    int n; cin >> n;
    string s; cin >> s;

    if(n==1) {
        cout << 4 << ' ' << 2 << '\n';
        return;
    }

    int sum=0;
    for(char c:s) sum+=c-48;

    vector<string> v;
    for(int i=0;i<n;i++) {
        int r = 3 - (sum-s[i]+48)%3;
        r = (r%3+3)%3;
        if(i==0 && r==0) r=3;

        string tmp=s;
        for(int j=r;j<10;j+=3) if(s[i]-48 != j) {
            tmp[i]=j+48;
            v.push_back(tmp);
            if(v.size()==n) {
                for(auto i:v) cout << i << ' ' << 3 << '\n';
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}