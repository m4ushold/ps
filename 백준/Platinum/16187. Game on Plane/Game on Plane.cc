#include <bits/stdc++.h>
using namespace std;

int N, G[5050]={0,0,1};

int mex(vector<int> &v) {
    set<int> s(v.begin(),v.end());
    int m=0;
    while(s.count(m)) m++;
    return m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=3;i<=5000;i++) {
        vector<int> v;
        for(int j=0;j<=(i-2)/2;j++) v.push_back(G[j]^G[i-2-j]);
        G[i]=mex(v);
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << (G[n] ? "First\n" : "Second\n");
    }
    return 0;
}