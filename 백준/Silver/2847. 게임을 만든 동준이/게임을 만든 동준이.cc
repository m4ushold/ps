#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    reverse(v.begin(),v.end());
    int g=v[0]+1, cnt=0;
    for(int i:v) {
        if(i>=g) cnt+=i-g+1;
        g=min(i,g-1);
    }
    cout << cnt;
    return 0;
}