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
    int n=s.size();
    vector<int> v=GetFail(s);

    for(int i=1;i<n;i++) {
        int m=i+1-v[i];
        if((i+1)%m==0 && (i+1)/m>1) cout << i+1 << ' ' << (i+1)/m << '\n';
    }
    return 0;
}