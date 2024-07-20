#include <bits/stdc++.h>
using namespace std;

void sol(int id) {
    int n, dap=0; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    while(v.size()) {
        int i=min_element(v.begin(),v.end())-v.begin();
        dap+=min(i,(int)v.size()-1-i);
        v.erase(v.begin()+i);
    }
    
    cout << "Case #" << id << ": " << dap << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}