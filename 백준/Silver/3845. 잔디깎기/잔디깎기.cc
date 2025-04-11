#include <bits/stdc++.h>
using namespace std;

bool chk(vector<double> v, double w) {
    double x=0;
    for(auto i:v) {
        if(x < i-w/2) return 0;
        x = i+w/2;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    double w;
    while(cin >> n >> m >> w && n) {
        vector<double> a(n),b(m);
        for(double &i:a) cin >> i;
        for(double &i:b) cin >> i;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        a.push_back(75+w/2);
        b.push_back(100+w/2);
        cout << (chk(a,w) && chk(b,w) ? "YES\n" : "NO\n");
    }
    return 0;
}