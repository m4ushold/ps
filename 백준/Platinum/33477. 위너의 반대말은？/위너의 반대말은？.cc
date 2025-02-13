#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int n,m,q;
 
pair<int,int> qry(int i) {
    cout << "? " << i << endl;
    int mn, mx; cin >> mn >> mx;
    return {mn,mx};
}
 
void ans(int x, int y) {
    cout << "! " << x << ' ' << y << endl;
}
 
int bin(int i, int x) { // x is 1 or n
    int l=i, r=min(i+m-1,n);
    while(l<r) {
        int m=l+r+1>>1;
        if(x==1 ? qry(m).first!=x : qry(m).second!=x) r=m-1;
        else l=m;
    }
    return l;
}
 
void st1() {
    int a=n,b=n;
    for(int i=2;i<=n;i++) {
        auto [mn,mx] = qry(i);
        if(mn != 1) a=i-1;
        if(mx != n) b=i-1;
    }
    ans(a,b);
}
void st2() {
    int a=0,b=0;
    for(int i=1;i<=n;i+=100) {
        auto [mn,mx] = qry(i);
        if(mn==1) a=i;
        if(mx==n) b=i;
    }
    ans(bin(a,1),bin(b,n));
}
 
int tri(int l, int r, int x) {
    while(l<r) {
        int m1=(l*2+r)/3, m2=(l+r*2+1)/3;
        auto [aa,bb]=qry(m1);
        auto [cc,dd]=qry(m2);
        if(aa == x || cc == x) return aa==x ? m1 : m2;
        else if(x == n ? (aa > cc) : (aa < cc)) r=m2-1;
        else l=m1+1;
    }
    if(qry(l).first==x) return l;
    return r;
}
 
void st3() {
    auto [a,z]=qry(1);
    auto [b,zz]=qry(2);
    if(a==1 && b==n) ans(1,2);
    else if(a==n && b==1) ans(2,1);
    else if(a==1 || b==1) {
        ans(a==1 ? 1 : 2,tri(2,n,n));
    } else if(a==n || b==n) {
        ans(tri(2,n,1),a==n ? 1 : 2);
    } else if(a < b) {
        int l=3, r=n, m, mn=0, mx=0;
        while(l<r) {
            m = l+r>>1;
            auto [aa,bb]=qry(m);
            auto [cc,dd]=qry(m+1);
            if(aa==1) mn=m;
            else if(cc==1) mn=m+1;
            if(aa==n) mx=m;
            else if(cc==n) mx=m+1;
 
            if(aa==1 || cc==1 || aa==n || cc==n || aa>cc) break;
            else if(b<aa) l=m+1;
            else r=m-1;
        }
        if(!mn) mn=tri(m+1,r,1);
        if(!mx) mx=tri(l,m,n);
        ans(mn,mx);
    } else {
        int l=3, r=n, m, mn=0, mx=0;
        while(l<r) {
            m = l+r>>1;
            auto [aa,bb]=qry(m);
            auto [cc,dd]=qry(m+1);
            if(aa==1) mn=m;
            else if(cc==1) mn=m+1;
            if(aa==n) mx=m;
            else if(cc==n) mx=m+1;
 
            if(aa==1 || cc==1 || aa==n || cc==n || aa<cc) break;
            else if(a>aa) l=m+1;
            else r=m-1;
        }
        if(!mn) mn=tri(l,m,1);
        if(!mx) mx=tri(m+1,r,n);
        ans(mn,mx);
    }
}
 
int Find_min(int l, int r) {
    while(l<r) {
        int m=l+r>>1;
        auto [a,b]=qry(m);
        auto [c,d]=qry(m+1);
        if(a==1) return bin(m,1);
        else if(c==1) return bin(m+1,1);
        else if(b<d) r=m;
        else l=m+1;
    }
    return l;
}
 
int Find_max(int l, int r) {
    while(l<r) {
        int m=l+r>>1;
        auto [a,b]=qry(m);
        auto [c,d]=qry(m+1);
        if(b==n) return bin(m,n);
        else if(d==n) return bin(m+1,n);
        else if(b>d) r=m;
        else l=m+1;
    }
    return l;
}
 
void st4() {
    auto [a,b]=qry(1);
    auto [c,d]=qry(2);
    int mn=0, mx=0;
    if(a==1) mn=bin(1,1);
    else if(c==1) mn=bin(2,1);
    if(b==n) mx=bin(1,n);
    else if(d==n) mx=bin(2,n);
 
    if(mn && !mx) mx=Find_max(mn+1,n);
    if(mx && !mn) mn=Find_min(mx+1,n);
    if(mn && mx) {ans(mn,mx);return;}
 
    if(a < c) {
        int l=3, r=n, m;
        while(l<r) {
            m = l+r>>1;
            auto [aa,bb]=qry(m);
            auto [cc,dd]=qry(m+1);
            if(aa==1) mn=bin(m,1);
            else if(cc==1) mn=bin(m+1,1);
            if(bb==n) mx=bin(m,n);
            else if(dd==n) mx=bin(m+1,n);
 
            if(aa==1 || cc==1 || bb==n || dd==n || aa>cc) break;
            else if(c<aa) l=m;
            else r=m;
        }
        
        if(!mn) mn = Find_min(m,r);
        if(!mx) mx = Find_max(l,m);
        ans(mn,mx);
    } else {
        int l=3, r=n, m;
        while(l<r) {
            m = l+r>>1;
            auto [aa,bb]=qry(m);
            auto [cc,dd]=qry(m+1);
            if(aa==1) mn=bin(m,1);
            else if(cc==1) mn=bin(m+1,1);
            if(bb==n) mx=bin(m,n);
            else if(dd==n) mx=bin(m+1,n);
 
            if(aa==1 || cc==1 || bb==n || dd==n || aa<cc) break;
            else if(a>aa) l=m;
            else r=m;
        }
        
        if(!mn) mn = Find_min(l,m);
        if(!mx) mx = Find_max(m,r);
        ans(mn,mx);
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    if(n==101) st1();
    else if(n==8000) st2();
    else if(n==2500) st3();
    else st4();
    return 0;
}