#include <bits/stdc++.h>
using namespace std;

int N, B, Q, A[101010], S[101010];

void upd(int i, int x) {
    A[i]=x;
    memcpy(S+i/B*B, A+i/B*B, 4*B);
    sort(S+i/B*B,S+(i/B+1)*B);
}

int qry(int l, int r, int k) {
    int cnt=0;
    while(l<=r && l%B) cnt+=A[l++]>k;
    while(l<=r && r%B+1!=B) cnt+=A[r--]>k;
    if(l<=r) for(int i=l/B;i<=r/B;i++) cnt+=S+(i+1)*B-upper_bound(S+i*B, S+(i+1)*B, k);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N, B=sqrt(N);
    for(int i=1;i<=N;i++) cin >> A[i], S[i]=A[i];
    for(int i=0;i<=N/B;i++) sort(S+i*B,S+(i+1)*B);
    cin >> Q;
    for(int q=0,a,i,j,k;q<Q;q++) {
        cin >> a >> i;
        if(a&1) cin >> j >> k, cout << qry(i,j,k) << '\n';
        else cin >> k, upd(i, k);
    }
    return 0;
}