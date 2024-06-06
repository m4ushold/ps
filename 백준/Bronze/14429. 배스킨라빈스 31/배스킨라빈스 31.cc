#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    pair<int,int> a(1e9,1e9);
    for(int i=1;i<=t;i++) {
        int j, m; cin >> j >> m;
        int r=(j-1)%(m+1), cnt=1;
        while(r<j-m-1) r+=m+1, cnt+=2;
        if(r!=j) cnt++;
        a=min(a,{cnt,i});
    }
    cout << a.second << ' ' << a.first;
    return 0;
}