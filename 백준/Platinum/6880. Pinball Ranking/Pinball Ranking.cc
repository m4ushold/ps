#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<17;
struct Seg {
    ll T[sz<<1];
    void bld() { for(int i=sz-1;i>=1;i--) T[i]=T[i*2]+T[i*2+1]; }
    void upd(int i, int x) {
        T[i|=sz]+=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
    }
    ll& operator[](int i) {return T[sz|i];}
    ll qry(int l, int r) {
        ll ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l++];
            if(~r&1) ret+=T[r--];
        }
        return ret;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n), a;
    for(int &i:v) cin >> i;
    a=v;
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    for(int &i:v) i=lower_bound(a.begin(),a.end(),i)-a.begin();

    ll sum=0;
    for(int i:v) {
        sum+=seg.qry(i+1,sz-1)+1;
        seg.upd(i,1);
    }
    cout << fixed << setprecision(2) << (double)sum/n;
    
    return 0;
}