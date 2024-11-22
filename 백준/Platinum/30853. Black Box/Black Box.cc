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
} seg;

int A[202020];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    swap(v[v.back()%(n-1)], v[0]);

    vector<int> res;
    res.push_back(v[0]);

    for(int i=1;i<n;i++) seg.upd(i, 1);

    int t=v[0];
    A[0] = v[0];
    for(int i=1,p=1;i<n;i++) {
        if(seg.T[1]) {
            p=(p+t-1)%seg.T[1];
            p=!p?seg.T[1]:p;
        }
        int j=seg.kth(p);
        t = A[j] = v[i];
        seg.upd(j,0);
    }
    for(int i=0;i<n;i++) cout << A[i] << '\n';
    return 0;
}