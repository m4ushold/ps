#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool chk(vector<int> &a, vector<int> &b) {
    for(int i=0;i<a.size();i++) if(a[i]!=b[i]) return 1;
    return 0;
}

void sol(int tc) {
    int n,k; cin >> n >> k;
    vector<int> v(n), a;
    for(int &i:v) cin >> i;
    a=v;
    sort(a.begin(),a.end());

    int cnt=0;
    while(chk(a,v)) {
        for(int i=0;i<n-k+1;i++) sort(v.begin()+i,v.begin()+i+k);
        cnt++;
    }
    cout << cnt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}