#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n), d(n), p(n);
    for(int &i:v) cin >> i;
    for(int i=1;i<n;i++) {
        if(v[i-1]<=v[i]) d[i]=d[i-1]+1;
        if(v[i-1]>=v[i]) p[i]=p[i-1]+1;
    }
    cout << max(*max_element(d.begin(),d.end()), *max_element(p.begin(),p.end()))+1;
    return 0;
}