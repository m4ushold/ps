#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

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

void sol(int tc) {
    int n; cin >> n;
    string s; cin >> s;
    auto [sa,lcp] = sfx(s);
    vector<int> ans(n);
    for(int i=0;i<n;i++) {
        ans[sa[i]] = lcp[i];
        if(i+1<n) ans[sa[i]] = max(ans[sa[i]], lcp[i+1]);
    }
    for(int i:ans) cout << i << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}