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
    int n; cin >> n;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    int k; cin >> k;
    vector<int> a(n);
    iota(a.begin(),a.end(),0);
    int dap=0;
    do {
        string ss="";
        for(int i:a) ss+=v[i];
        int l=ss.length(), m=l-GetFail(ss).back();
        if(k==1 && !(l%m==0 && l/m>1)) dap++;
        else if(l%m==0 && l/m==k) dap++;
    } while(next_permutation(a.begin(),a.end()));
    cout << dap;
    return 0;
}