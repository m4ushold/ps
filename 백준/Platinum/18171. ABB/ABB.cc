#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(const string &inp){
    int n = inp.size() * 2 + 1;
    vector<int> ret(n);
    string s = "#";
    for(auto i : inp) s += i, s += "#";
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
    int n; string s; cin >> n >> s;
    auto v = manacher(s);

    int mx = *max_element(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++) {
        if(i + v[i] == 2*n) {
            int j = (i-v[i])/2;
            cout << j;
            break;
        }
    }
    return 0;
}