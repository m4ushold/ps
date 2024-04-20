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
vector<int> KMP(const string &s, const string &p){
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

char A[202];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        memset(A,0,sizeof A);
        string a,w,s; cin >> a >> w >> s;
        for(int i=0,j=a.size()-1;i<a.size();j=i++) A[a[i]]=a[j];
        vector<int> dap;
        for(int i=0;i<a.size();i++) {
            if(KMP(s,w).size()==1) dap.push_back(i);
            for(char &c:s) c=A[c];
        }
        if(dap.empty()) cout << "no solution\n";
        else if(dap.size()==1) cout << "unique: " << dap.back() << '\n';
        else {
            cout << "ambiguous: ";
            for(int i:dap) cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}