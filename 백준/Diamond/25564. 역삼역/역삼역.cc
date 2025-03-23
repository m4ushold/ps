#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> manacher(const string &inp){
    int n = inp.size() * 2 + 1;
    vector<int> ret(n);
    string s = "#";
    for(auto i : inp) s += i, s += "#";
    for(int i=0, p=-1, r=-1; i<n; i++){
        ret[i] = i <= r ? min(r-i, ret[2*p-i]) : 0;
        while(i-ret[i]-1 >= 0 && i+ret[i]+1 < n && s[i-ret[i]-1] == s[i+ret[i]+1])
        ret[i]++;
        if(i+ret[i] > r) r = i+ret[i], p = i;
    }
    return ret;
}

tuple<vector<int>,vector<int>,vector<int>> sfx(const string& s) {
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
    return {sa,lcp,pos};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    string s; cin >> s;
    auto p = manacher(s);
    vector<pair<int,int>> interval;
    for(int i=0,o=k&1?k:k+1,e=k&1?k+1:k;i<p.size();i++) if(p[i] >= k) {
        int len = i&1 ? o : e;
        interval.push_back({(i-len)/2, (i+len-1)/2});
    }
    vector<int> idx(n);
    int mn=n;
    for(int i=n-1;i>=0;i--) {
        while(interval.size() && interval.back().first >= i) mn=min(mn, interval.back().second), interval.pop_back();
        idx[i] = mn;
    }
    
    auto [sa,lcp,pos] = sfx(s);
    ll ans = 0;
    for(int i=0;i<n;i++) ans += n-min(n,max(idx[i], lcp[pos[i]]+i));
    cout << ans;
    return 0;
}