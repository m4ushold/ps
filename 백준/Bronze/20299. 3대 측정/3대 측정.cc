#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k,l; cin >> n >> k >> l;
    vector<int> v;
    for(int i=0,a,b,c;i<n;i++) {
        cin >> a >> b >> c;
        if(a+b+c >=k && a>=l && b>=l && c>=l) v.push_back(a), v.push_back(b), v.push_back(c);
    }
    cout << v.size()/3 << '\n';
    for(int i:v) cout << i << ' ';
    return 0;
}