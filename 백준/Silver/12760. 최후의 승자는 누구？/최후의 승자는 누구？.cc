#include <bits/stdc++.h>
using namespace std;

int S[101];
vector<int> C[101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=0,a;j<m;j++) cin >> a, C[i].push_back(a);
        sort(C[i].begin(), C[i].end(), greater<>());
    }
    for(int i=0;i<m;i++) {
        int mx=0;
        vector<int> v;
        for(int j=1;j<=n;j++) {
            if(mx<C[j][i]) mx=C[j][i], v.clear(), v.push_back(j);
            else if(mx==C[j][i]) v.push_back(j);
        }
        for(int j:v) S[j]++;
    }
    int mx=0;
    vector<int> v;
    for(int i=1;i<=n;i++) {
        if(mx<S[i]) mx=S[i], v.clear(), v.push_back(i);
        else if(mx==S[i]) v.push_back(i);
    }
    sort(v.begin(),v.end());
    for(int i:v) cout << i << ' ';
    return 0;
}