#include <bits/stdc++.h>
using namespace std;

int N, B, Q, A[101010];
vector<int> S[404];

void upd(int i, int x) {
    int v=A[i]; A[i]=x, i/=B;
    S[i].erase(lower_bound(S[i].begin(), S[i].end(), v));
    S[i].insert(lower_bound(S[i].begin(),S[i].end(), x), x);
}

int qry(int l, int r, int k) {
    int cnt=0;
    while(l<=r && l%B) cnt+=A[l++]>k;
    while(l<=r && r%B+1!=B) cnt+=A[r--]>k;
    if(l<=r) for(int i=l/B;i<=r/B;i++) cnt+=S[i].end()-upper_bound(S[i].begin(), S[i].end(), k);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N, B=1e3;
    for(int i=1;i<=N;i++) cin >> A[i], S[i/B].push_back(A[i]);
    for(int i=0;i<=N/B;i++) sort(S[i].begin(),S[i].end());
    cin >> Q;
    for(int q=0,a,i,j,k;q<Q;q++) {
        cin >> a >> i;
        if(a&1) cin >> k, upd(i, k);
        else cin >> j >> k, cout << qry(i,j,k) << '\n';
    }
    return 0;
}