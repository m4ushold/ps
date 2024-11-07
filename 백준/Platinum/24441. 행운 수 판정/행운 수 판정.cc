#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Seg {
    static const int sz=1<<20;
    int T[sz<<1];
    void bld() {
        for(int i=sz+1;i<2*sz;i+=2) T[i]=1;
        for(int i=sz-1;i>=1;i--) T[i]=T[i*2]+T[i*2+1];
    }
    void update(int i, int x) {
        T[i|=sz]=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
    }
    int kth(int k) {
        int i=1;
        while(i<sz) {
            if(k<=T[i*2]) i*=2;
            else k-=T[i*2], i=i*2+1;
        }
        return i^sz;
    }
} seg;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    seg.bld();
    int i, k=2;;
    while((i=seg.kth(k)) < 1e6) {
        int r=seg.T[1]/i*i;
        while(r>0) seg.update(seg.kth(r), 0), r-=i;
        k++;
    }
    
    int t,x; cin >> t;
    while(t--) cin >> x, cout << (seg.T[seg.sz|x] ? "lucky\n" : "unlucky\n");
    return 0;
}