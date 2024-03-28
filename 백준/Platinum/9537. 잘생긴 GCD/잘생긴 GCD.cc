#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N, A[100000];

ll dnc(int l, int r)
{
    if (l==r) return A[l];
    else if(l+1==r) return max(2*gcd(A[l],A[r]), max(A[l],A[r]));

    ll m = (l+r)/2, a=0, g=0, t;
    
    a = max(a, dnc(l, m-1));
    a = max(a, dnc(m+1, r));

    vector<pair<ll,ll>> ll, rr;
    g=A[m];
    for(int i=m;i>=l;i--) {
        t=gcd(g,A[i]);
        if(g!=t) { ll.push_back({g,i+1}); }
        g=t; 
    }
    if (ll.empty() || ll[ll.size()-1].second != l) ll.push_back({g,l});

    g=A[m];
    for(int i=m;i<=r;i++) {
        t=gcd(g,A[i]);
        if(g!=t) { rr.push_back({g,i-1}); }
        g=t; 
    }
    if (rr.empty() || rr[rr.size()-1].second != r) rr.push_back({g,r});

    for(auto lll : ll) {
        for(auto rrr : rr) {
            a = max(a, (rrr.second-lll.second+1)*gcd(lll.first,rrr.first));
        }
    }

    return a;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> N;
        for(int i=0;i<N;i++) cin >> A[i];
        cout << dnc(0, N-1) << '\n';
    }
    return 0;
}