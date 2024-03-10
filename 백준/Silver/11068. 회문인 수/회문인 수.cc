#include <bits/stdc++.h>
using namespace std;

bool chk(int n, int b) {
    vector<int> v;
    while(n) v.push_back(n%b), n/=b;
    for(int i=0;i<v.size()/2;i++) if(v[i]!=v[v.size()-i-1]) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n,f=0; cin >> n;
        for(int b=2;b<=64;b++) f|=chk(n,b);
        cout << f << '\n';
    }
    return 0;
}