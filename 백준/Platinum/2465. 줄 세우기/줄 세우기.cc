#include <bits/stdc++.h>
using namespace std;

struct Seg {
    static const int sz=1<<17;
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]+=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
    }
    int kth(int k) {
        int i=1;
        while(i<sz) {
            if(k<=T[i*2]) i*=2;
            else k-=T[i*2], i=i*2+1;
        }
        return sz^i;
    }
} seg;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n), a, o(n);
    for(int &i:v) cin >> i;
    a=v;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int &i:a) i=lower_bound(v.begin(),v.end(),i)-v.begin(), seg.upd(i,1);
    
    for(int &i:o) cin >> i;
    reverse(o.begin(),o.end());
    for(int &i:o) i=seg.kth(i+1), seg.upd(i,-1);
    reverse(o.begin(),o.end());
    for(int i:o) cout << v[i] << ' ';
    cout << '\n';
    return 0;
}