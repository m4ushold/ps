#include <bits/stdc++.h>
using namespace std;

vector<int> B[202020];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        B[i%k].push_back(v[i]);
    }
    for(int i=0;i<k;i++) sort(B[i].begin(),B[i].end());
    vector<int> tmp;
    for(int i=0;i<n;i++) {
        tmp.push_back(B[i%k][i/k]);
    }
    
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++) if(v[i]!=tmp[i]) {
        return cout << "No", 0;
    }
    cout << "Yes";
    return 0;
}