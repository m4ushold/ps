#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<19, inf=1e9;

int N, Q;
char A[sz];

struct Seg {
    int T[sz<<1], R[sz];
    void upd(int i, int x) {
        T[i|=sz] = x;
        while(i/=2) T[i]=min(T[i*2], T[i*2+1]);
    }
    int query(int l, int r) {
        if(l>r) return 1e9;
        int res=1e9;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res=min(res,T[l++]);
            if(~r&1) res=min(res,T[r--]);
        }
        return res;
    }
    int mn(int l, int r) {
        return l==r?inf:query(min(R[l],R[r])+1, max(R[l],R[r]));
    }
} seg;

struct HLD {
    int TOP[sz], P[sz], D[sz], SZ[sz], IN[sz], I[sz];
    vector<int> GG[sz], G[sz];
    void connect(int u, int v) {
        GG[u].push_back(v), GG[v].push_back(u);
    }
    void d1(int v=1, int p=-1) {
        for(int i:GG[v]) if(i!=p) G[v].push_back(i), D[i]=D[v]+1, P[i]=v, d1(i,v);
    }
    void d2(int v=1) {
        SZ[v]=1;
        for(int &i:G[v]) {
            d2(i), SZ[v]+=SZ[i];
            if(SZ[i]>SZ[G[v][0]]) swap(i,G[v][0]);
        }
    }
    void d3(int v) {
        static int pv=0; IN[v]=++pv, I[pv]=v;
        for(int i:G[v]) TOP[i]= (i==G[v][0] ? TOP[v] : i), d3(i);
    }
    void build() {
        d1(), d2(), d3(TOP[1]=1);
    }
    vector<pair<int,int>> query(int u, int v) {
        vector<pair<int,int>> l, r;
        for(;TOP[u]!=TOP[v];) {
            if(D[TOP[u]] < D[TOP[v]]) r.push_back({TOP[v], v}), v=P[TOP[v]];
            else l.push_back({u,TOP[u]}), u=P[TOP[u]];
        }
        l.push_back({u,v});
        while(r.size()) l.push_back(r.back()), r.pop_back();
        return l;
    }
} tree;

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

pair<int,int> idx(pair<int,int> path) {
    auto [s,e] = path;
    int st, len = abs(tree.IN[s]-tree.IN[e])+1;
    if(tree.IN[s] <= tree.IN[e]) st = tree.IN[s] - 1;
    else st = 2*N - tree.IN[s];
    return {st,len};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1,u,v;i<N;i++) cin >> u >> v, tree.connect(u,v);
    tree.build();
    
    string str;
    for(int i=1;i<=N;i++) str+=A[tree.I[i]];
    for(int i=N;i;i--) str+=A[tree.I[i]];
    auto [sa,lcp] = sfx(str);
    for(int i=0;i<sa.size();i++) seg.R[sa[i]] = i;
    for(int i=0;i<lcp.size();i++) seg.upd(i, lcp[i]);

    // for(int i:sa) cout << i << ' '; cout << endl;
    // for(int i:lcp) cout << i << ' '; cout << endl;
    // 0 1 2 3 4 5 6 7 8 9
    // B B A C C C C A B B
    // 7 2 9 1 8 0 6 5 4 3 
    // 0 1 0 1 1 2 0 1 2 3 

    // for(int i:sa) cout << i << " "; cout << endl;
    // for(int i:lcp) cout << i << ' '; cout << endl;
    // for(int i=0;i<sa.size();i++) cout << seg.R[i] << ' ';
    // cout << endl;

    cin >> Q;
    for(int t=0,a,b,c,d;t<Q;t++) {
        cin >> a >> b >> c >> d;
        auto p = tree.query(a,b);
        auto q = tree.query(c,d);
        // for(auto [i,j]:p) cout << "(" << i << ", " << j << ") "; cout << endl;
        // cout << a << " -> " << b << endl;
        // for(auto k:p) {
        //     auto [i,j] = idx(k);
        //     cout << "(" << i << ", " << j << ") ";
        // }
        // cout << endl;
        // cout << c << " -> " << d << endl;
        // for(auto k:q) {
        //     auto [i,j] = idx(k);
        //     cout << "(" << i << ", " << j << ") ";
        // }
        // cout << endl;
        // for(auto k:p) {
        //     auto [i,j]=idx(k);
        //     cout << str.substr(i-1,j);
        // }
        // cout << endl;

        int dap=0;
        for(int i=0,j=0,ii=0,jj=0;i<p.size() && j<q.size();) {
            auto [ps,plen] = idx(p[i]);
            auto [qs,qlen] = idx(q[j]);
            ps += ii, plen -= ii;
            qs += jj, qlen -= jj;

            int mn = seg.mn(ps, qs);
            dap += min({mn, plen, qlen});
            if(mn < min(plen, qlen)) break;

            plen == min(plen, qlen) ? i++, ii=0 : ii+=qlen;
            qlen == min(plen,qlen) ? j++, jj=0 : jj+=plen;
        }
        cout << dap << '\n';
    }
    return 0;
}