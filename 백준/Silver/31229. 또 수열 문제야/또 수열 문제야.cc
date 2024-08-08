#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int S[202020]={1,1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i*i<202020;i++) if(!S[i]) for(int j=2*i;j<202020;j+=i) S[j]=1;
    int n; cin >> n;
    vector<int> v;
    for(int i=2;v.size()<n;i++) if(!S[i]) v.push_back(i);
    for(int i:v) cout << i << ' ';
    cout << endl;
    return 0;
}