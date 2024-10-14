#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,t; cin >> n >> t;
    vector<int> v(n), a;
    for(int i=1;i*i<=t;i++) if(t%i==0) a.push_back(i), a.push_back(t/i);
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    a.push_back(1e9);

    int dap=0;
    for(int &i:v) {
        cin >> i;
        if(i>t) dap+=i-t;
        else {
            int j=upper_bound(a.begin(),a.end(), i)-a.begin();
            dap+=min(abs(i-a[j]), abs(i-a[j-1]));
        }
    }
    cout << dap;
    return 0;
}