#include <bits/stdc++.h>
using namespace std;

constexpr int sz=1<<18;
struct {
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i/=2) T[i]=T[i*2]+T[i*2+1];
    }
    int kth(int k) {
        int i=1;
        while(i<sz) {
            if(k<=T[i*2]) i*=2;
            else k-=T[i*2], i=i*2+1;
        }
        return i^sz;
    }
    int qry(int l, int r) {
        int res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;

int A[202020];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    swap(v[v.back()%(n-1)], v[0]);

    for(int i=1;i<n;i++) seg.upd(i, 1);
    
    A[0] = v[0];
    int idx=0;
    for(int i=1;i<n;i++) {
        int sz=n-i;
        int k = (v[i-1]-1+sz)%sz+1;
        if(seg.qry(idx, n) < k) {
            k-=seg.qry(idx,n);
            idx = seg.kth(k);
            A[idx] = v[i];
        } else {
            idx = seg.kth(seg.qry(0,idx)+k);
            A[idx] = v[i];
        }
        seg.upd(idx, 0);
    }

    for(int i=0;i<n;i++) cout << A[i] << '\n';
    return 0;
}