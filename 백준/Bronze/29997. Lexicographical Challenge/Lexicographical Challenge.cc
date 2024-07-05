#include <bits/stdc++.h>
using namespace std;

string S[101010];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int k; cin >> k;
    for(int i=0;i<s.size();i++) S[i%k]+=s[i];
    for(int i=0;i<k;i++) sort(S[i].begin(),S[i].end());
    
    for(int i=0;i<s.size();i++) cout << S[i%k][i/k];
    return 0;
}