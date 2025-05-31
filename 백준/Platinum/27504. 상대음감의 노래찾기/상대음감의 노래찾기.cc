#include <bits/stdc++.h>
using namespace std;

vector<int> GetFail(const vector<int> &p){
    int n = p.size();
    vector<int> fail(n);
    for(int i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}
vector<int> KMP(const vector<int> &s, const vector<int> &p){
    int n = s.size(), m = p.size();
    vector<int> fail = GetFail(p), ret;
    for(int i=0, j=0; i<s.size(); i++){
        while(j && s[i] != p[j]) j = fail[j-1];
            if(s[i] == p[j]){
            if(j + 1 == m) ret.push_back(i-m+1), j = fail[j];
            else j++;
        }
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<vector<int>> v(n);
    for(auto &vec:v) {
        int nn; cin >> nn;
        vector<int> t(nn);
        for(int &i:t) cin >> i;
        for(int i=1;i<nn;i++) vec.push_back(t[i]-t[i-1]);
    }
    cin >> n;
    vector<int> t(n), a;
    for(int &i:t) cin >> i;
    for(int i=1;i<n;i++) a.push_back(t[i]-t[i-1]);
    
    int c=0;
    for(int i=0;i<v.size();i++) {
        if(KMP(v[i], a).size()) cout << i+1 << ' ', c++;
    }
    if(c==0) cout << -1;

    return 0;
}