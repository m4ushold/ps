#include <bits/stdc++.h>
using namespace std;

vector<int> GetFail(const string &p){
    int n = p.size();
    vector<int> fail(n);
    for(int i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int mx=0;
    for(int i=0;i<s.size();i++) {
        vector<int> v=GetFail(s.substr(i, s.size()-i));
        mx=max(mx, *max_element(v.begin(),v.end()));
    }
    cout << mx;
    return 0;
}