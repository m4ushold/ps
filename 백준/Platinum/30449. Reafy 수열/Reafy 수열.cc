#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;

bool cmp(const p &a, const p &b) { return a.first*b.second<a.second*b.first; }

int n, k, g[5050][5050]; 

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<pair<int,int>> v;
    v.emplace_back(1,1);
    for(int i=1;i<=n;i++) for(int j=0;j<i;j++) {
        g[i][j]=j?g[j][i%j]:i;
        if(g[i][j]==1) v.emplace_back(j,i); 
    }
    nth_element(v.begin(),v.begin()+k-1,v.end(),cmp);
    cout << v[k-1].first << ' ' << v[k-1].second << '\n';
    return 0;
}