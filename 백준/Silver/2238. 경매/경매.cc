#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<string> A[10101];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int u, n; cin >> u >> n;
    for(int i=0,a;i<n;i++) {
        string s; cin >> s >> a;
        A[a].push_back(s);
    }
    int mn=1e9;
    for(int i=1;i<=10'000;i++) if(A[i].size()) mn=min(mn,(int)A[i].size());
    for(int i=1;i<=10'000;i++) if(A[i].size()==mn) return cout << A[i].front() << ' ' << i, 0;
    return 0;
}