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
    int L; cin >> L;
    string s; cin >> s;
    cout << L-GetFail(s)[L-1];
    return 0;
}