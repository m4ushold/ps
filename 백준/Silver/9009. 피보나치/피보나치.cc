#include <bits/stdc++.h>
using namespace std;

int F[45]={1,1};

void sol() {
    int n; cin >> n;
    vector<int> v;
    for(int i=44;i>=0;i--) {
        if(F[i]<=n) n-=F[i], v.push_back(F[i]);
    }
    reverse(v.begin(),v.end());
    for(int i:v) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i<45;i++) F[i]=F[i-1]+F[i-2];
    int t; cin >> t;
    while(t--) sol();
    return 0;
}