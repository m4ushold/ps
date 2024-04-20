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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    vector<vector<int>> v(n);
    for(auto &vec:v) {
        int s; cin >> s;
        vec.resize(s);
        for(int &i:vec) cin >> i;
        vec.push_back(1e9);
        for(int i=s-1;i>=0;i--) vec.push_back(vec[i]);
    }

    for(int i=0;i+k-1<v[0].size()/2;i++) {
        vector<int> t(v[0].begin()+i, v[0].begin()+i+k);
        int f=1;
        for(auto vec:v) {
            if(!KMP(vec,t).size()) {f=0; break;}
        }
        if(f) {cout << "YES"; return 0;}
    }
    cout << "NO";

    return 0;
}