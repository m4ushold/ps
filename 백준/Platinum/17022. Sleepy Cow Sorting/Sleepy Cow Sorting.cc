#include <bits/stdc++.h>
using namespace std;

const int sz=1<<17;
struct {
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i/=2) T[i]=T[i*2]+T[i*2+1];
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
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    int p=0;
    for(int i=n-1;i;i--) if(v[i]<v[i-1]) {
        p=i;
        break;
    }
    for(int i=p;i<n;i++) seg.upd(v[i],1);
    cout << p << '\n';

    for(int i=0;i<p;i++) {
        cout << p-i-1+seg.qry(0,v[i]) << ' ';
        seg.upd(v[i],1);
    }
    return 0;
}