#include <bits/stdc++.h>
using namespace std;

int N, G[1010]={0,0,1};

int mex(vector<int> &v) {
    set<int> s(v.begin(),v.end());
    int m=0;
    while(s.count(m)) m++;
    return m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=3;i<=N;i++) {
        vector<int> v;
        for(int j=0;j<=(i-2)/2;j++) v.push_back(G[j]^G[i-2-j]);
        G[i]=mex(v);
    }
    cout << (G[N] ? 1 : 2);
    return 0;
}