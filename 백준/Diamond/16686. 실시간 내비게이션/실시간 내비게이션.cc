#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using node_t=pair<ll,ll>; // p+q , bi
using node2_t=tuple<ll,ll,ll,ll,ll>;

ll N, Q, AA[303030], BB[303030], CC[303030];

struct SegTree {
    static const int sz=1<<17;
    const node_t id={-1,-1}, lid={0,0};
    node_t A[sz<<1], B[sz<<1], L[sz<<1];
    node2_t C[sz<<1]; // uu ud du dd
    node_t merge1(node_t a, node_t b) const {
        if(a==id || b==id) return max(a,b);
        return a.second-a.first < b.second-b.first ? a : b;
    }
    node_t merge2(node_t a, node_t b) const {
        if(a==id || b==id) return max(a,b);
        return a.first+a.second < b.first+b.second ? a : b;
    }
    node2_t merge3(node2_t a, node2_t b) const {
        auto [auu, aud, adu, add, i]=a;
        auto [buu, bud, bdu, bdd, j]=b;
        if(i==0) return b;
        if(j==0) return a;
        return {
            min(auu+AA[i+1]+buu, aud+BB[i+1]+bdu), 
            min(auu+AA[i+1]+bud, aud+BB[i+1]+bdd),
            min(adu+AA[i+1]+buu, add+BB[i+1]+bdu),
            min(adu+AA[i+1]+bud, add+BB[i+1]+bdd),
            j
        };
    }
    void merge(int i) {
        A[i]=merge1(A[i*2],A[i*2+1]);
        B[i]=merge2(B[i*2],B[i*2+1]); 
        C[i]=merge3(C[i*2],C[i*2+1]);
    }
    SegTree() { for(int i=0;i<sz*2;i++) A[i]=B[i]=id, L[i]=lid; }
    void build() {  for(int i=sz-1;i>=1;i--) merge(i); }
    void push(int i, int s, int e) {
        if(L[i]==lid) return;
        A[i].first+=L[i].first, B[i].first+=L[i].first;
        if(L[i].second) A[i].second=B[i].second=L[i].second;
        if(s!=e) for(int j:{i*2,i*2+1}) {
            L[j].first+=L[i].first;
            if(L[i].second) L[j].second=L[i].second;
        }
        L[i]=lid;
    }
    void upd(int l, int r, node_t v, int i=1, int s=0, int e=sz-1) {
        push(i,s,e);
        if(r<s || e<l) return;
        else if(l<=s && e<=r) {
            L[i].first+=v.first;
            if(v.second) L[i].second=v.second;
            push(i,s,e);
            return;
        }
        int m=s+e>>1;
        upd(l,r,v,i*2,s,m), upd(l,r,v,i*2+1,m+1,e);
        merge(i);
    }
    void upd1(int x, ll v, int i=1, int s=0, int e=sz-1) {
        if(s==e) {
            auto &[a,b,c,d,j]=C[i];
            b=c=v;
            return;
        }
        int m=s+e>>1;
        x<=m ? upd1(x,v,i*2,s,m) : upd1(x,v,i*2+1,m+1,e);
        C[i]=merge3(C[i*2],C[i*2+1]);
    }
    node_t qry11(int l, int r, int i=1, int s=0, int e=sz-1) {
        push(i,s,e);
        if(r<s || e<l) return id;
        else if(l<=s && e<=r) return A[i];
        int m=s+e>>1;
        return merge1(qry11(l,r,2*i,s,m),qry11(l,r,2*i+1,m+1,e));
    }
    ll qry1(int i) {
        auto [a,b]=qry11(1,i);
        return qry11(i,i).first+b-a;
    }
    node_t qry22(int l, int r, int i=1, int s=0, int e=sz-1) {
        push(i,s,e);
        if(r<s || e<l) return id;
        else if(l<=s && e<=r) return B[i];
        int m=s+e>>1;
        return merge2(qry22(l,r,2*i,s,m),qry22(l,r,2*i+1,m+1,e));
    }
    ll qry2(int i) {
        auto [a,b]=qry22(i,sz-1);
        return a+b-qry22(i,i).first;
    }
    node2_t qry33(int l, int r, int i=1, int s=0, int e=sz-1) {
        push(i,s,e);
        if(r<s || e<l) return {0,0,0,0,0};
        else if(l<=s && e<=r) return C[i];
        int m=s+e>>1;
        return merge3(qry33(l,r,2*i,s,m),qry33(l,r,2*i+1,m+1,e));
    }
    ll qry(string s, string e) {
        int l=stoi(s.substr(1)), r=stoi(e.substr(1));
        if(l > r) swap(s,e), swap(l,r);
        auto [uu,ud,du,dd,i]=qry33(l,r);
        ll a=qry1(l), b=qry2(r);
        if(s[0]=='N' && e[0]=='N') return min({uu,ud+b,du+a,dd+a+b});
        else if(s[0]=='N' && e[0]=='S') return min({uu+b,ud,du+a+b,dd+a});
        else if(s[0]=='S' && e[0]=='N') return min({uu+a,ud+a+b,du,dd+b});
        else return min({uu+a+b,ud+a,du+b,dd});
    }
} seg;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=2;i<=N;i++) cin >> AA[i], AA[i]+=AA[i-1];
    for(int i=2;i<=N;i++) cin >> BB[i], BB[i]+=BB[i-1];
    for(int i=1;i<=N;i++) cin >> CC[i];

    for(int i=1;i<=N;i++) {
        seg.A[seg.sz|i] = {AA[i]+BB[i],CC[i]};
        seg.B[seg.sz|i] = {AA[i]+BB[i],CC[i]};
        seg.C[seg.sz|i] = {0,CC[i],CC[i],0,i};
    }
    for(int i=N;i>1;i--) AA[i]-=AA[i-1], BB[i]-=BB[i-1];
    seg.build();

    cin >> Q;
    for(ll i=0,q,a,b;i<Q;i++) {
        cin >> q;
        if(q==1) {
            string s,e; cin >> s >> e;
            cout << seg.qry(s,e) << '\n';
        } else if(q==2) {
            cin >> a >> b;
            ll t=b-AA[a+1];
            AA[a+1]=b;
            seg.upd(a+1,N,{t,0});
        } else if(q==3) {
            cin >> a >> b;
            ll t=b-BB[a+1];
            BB[a+1]=b;
            seg.upd(a+1,N,{t,0});
        } else {
            cin >> a >> b;
            CC[a]=b;
            seg.upd(a,a,{0,b});
            seg.upd1(a,b);
        }
    }
    return 0;
}