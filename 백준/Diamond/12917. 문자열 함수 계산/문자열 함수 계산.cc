#include <bits/stdc++.h>
using namespace std;
using ll=long long;

pair<vector<int>,vector<int>> sfx(const string& s) {
    int n=s.size();
    vector<int> sa(n), pos(n), tmp(n);
    for(int i=0;i<n;i++) sa[i]=i, pos[i]=s[i];
    for(int k=1;;k*=2) {
        auto cmp = [&](int a, int b) {
            if(pos[a]!=pos[b]) return pos[a]<pos[b];
            if(a+k<n && b+k<n) return pos[a+k]<pos[b+k];
            return a>b;
        };
        sort(sa.begin(),sa.end(),cmp);
        for(int i=1;i<n;i++) tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
        for(int i=0;i<n;i++) pos[sa[i]]=tmp[i];
        if(tmp.back()+1==n) break;
    }

    vector<int> lcp(n);
    for(int i=0,j=0;i<n;i++,j=max(j-1,0)) {
        if(pos[i]==0) continue;
        while(sa[pos[i]-1]+j < n && sa[pos[i]]+j < n && s[sa[pos[i]-1]+j] == s[sa[pos[i]]+j]) j++;
        lcp[pos[i]]=j;
    }
    return {sa,lcp};
}

ll N, A[1<<17];

ll ff(ll n) {return n+1;}

ll dq(ll l, ll r) {
    if (l>r) return 0;
    if (l==r) return A[l]*2;
    ll m = (l+r)/2, ll=m-1, rr=m+1, mn=A[m], cnt=1, res=A[m]*2;
    while(l<=ll && rr<=r) {
        if(A[ll] > A[rr]) mn = min(mn, A[ll--]);
        else mn = min(mn, A[rr++]);
        res = max(res, mn*ff(++cnt));
    }
    while (l<=ll) {mn = min(mn, A[ll--]); res = max(res, mn*ff(++cnt));}
    while (rr<=r) {mn = min(mn, A[rr++]); res = max(res, mn*ff(++cnt));}
    
    return max({res,dq(l, m-1),dq(m+1, r)});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    auto [sa,lcp] = sfx(s);
    N=lcp.size();
    for(int i=0;i<N;i++) A[i]=lcp[i];
    cout << max(N,dq(0,N-1));
    return 0;
}