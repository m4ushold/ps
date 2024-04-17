#include <bits/stdc++.h>
using namespace std;

vector<int> A[202];
int C[202];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s, t; cin >> t >> s;
    for(int i=0;i<s.size();i++) A[s[i]].push_back(i), C[s[i]]++;
    for(char c:t) if(!C[c]) {cout << -1; return 0;}

    int i=-1, dap=0;
    for(char c:t) {
        auto it=upper_bound(A[c].begin(), A[c].end(), i);
        if(it==A[c].end()) {
            dap++, i=-1;
            it=upper_bound(A[c].begin(), A[c].end(), i);
        }
        i=*it;
    }
    cout << dap+1;
    
    return 0;
}