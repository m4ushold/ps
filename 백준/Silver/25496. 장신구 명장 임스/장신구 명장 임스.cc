#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int p,n; cin >> p >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    int i=0;
    while(p<200 && i<n) p+=v[i++];
    cout << i;
    return 0;
}