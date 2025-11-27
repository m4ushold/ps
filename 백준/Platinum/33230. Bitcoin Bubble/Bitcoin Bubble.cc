#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

ll N, A[101010], B[101010];

ll dnc(int l, int r) {
    if(l>r) return 0;
    if(l==r) return A[l]*B[l];
    int m = l+r>>1, li=m-1, ri=m+1;
    ll ans = A[m]*B[m], w=B[m], h=A[m];
    while(l<=li && ri<=r) {
        if(A[li] > A[ri]) h=min(h,A[li]), w+=B[li], li--;
        else h=min(h,A[ri]), w+=B[ri], ri++;
        ans = max(ans, h*w);
    }
    while(l<=li) h=min(h, A[li]), w+=B[li], li--, ans=max(ans, h*w);
    while(ri<=r) h=min(h, A[ri]), w+=B[ri], ri++, ans=max(ans, h*w);

    return max({dnc(l,m-1), ans, dnc(m+1,r)});
}

void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i] >> B[i];
    cout << dnc(1,N);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}