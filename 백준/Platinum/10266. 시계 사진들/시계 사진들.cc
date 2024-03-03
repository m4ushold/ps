#include <bits/stdc++.h>
using namespace std;

const int M=360'000;

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
    int n; cin >> n;
    vector<int> s(2*M), p(M);
    for(int i=0,a;i<n;i++) cin >> a, s[a]=1, s[a+M]=1;
    for(int i=0,a;i<n;i++) cin >> a, p[a]=1;
    cout << (KMP(s,p).size() ? "possible" : "impossible");
    return 0;
}