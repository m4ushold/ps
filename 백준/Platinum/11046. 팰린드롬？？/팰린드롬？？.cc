#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(const vector<int> &s){
    int n = s.size();
    vector<int> ret(n);
    for(int i=0, p=-1, r=-1; i<n; i++){
        ret[i] = i <= r ? min(r-i, ret[2*p-i]) : 0;
        while(i-ret[i]-1 >= 0 && i+ret[i]+1 < n && s[i-ret[i]-1] == s[i+ret[i]+1])
        ret[i]++;
        if(i+ret[i] > r) r = i+ret[i], p = i;
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n,q; cin >> n;
    vector<int> v(2*n+1);
    for(int i=1;i<2*n+1;i+=2) cin >> v[i];
    auto s=manacher(v);

    cin >> q;
    for(int i=0,a,b;i<q;i++) {
        cin >> a >> b;
        cout << (s[a+b-1] >= b-a+1) << '\n';
    }
    return 0;
};