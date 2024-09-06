#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    if(n>100) return cout << "Yes", 0;

    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) for(int k=j+1;k<n;k++) for(int w=k+1;w<n;w++) {
        if((v[i]^v[j]^v[k]^v[w]) == 0) return cout << "Yes", 0;
    }
    cout << "No";
    return 0;
}