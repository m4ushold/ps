#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[22][22];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][j];
    ll mn=LONG_LONG_MAX;
    for(int i=1;i<(1<<N)-2;i++) {
        vector<int> a,b;
        for(int j=0;j<N;j++) (i>>j)&1?a.push_back(j):b.push_back(j);
        ll aa=0,bb=0;
        for(int i:a) for(int j:a) aa+=A[i][j];
        for(int i:b) for(int j:b) bb+=A[i][j];
        mn=min(mn,abs(aa-bb));
    }
    cout << mn;
    return 0;
}