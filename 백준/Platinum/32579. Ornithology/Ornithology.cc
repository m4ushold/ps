#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int sz=1<<18;
struct Seg {
    int T[sz<<1];
    void update(int i, int x) {
        T[i|=sz]+=x;
        while(i>>=1) T[i]=T[i*2]+T[i*2+1];
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
    ll res=0;
    for(int i=1;i<=n;i++) {
        int t; cin >> t;
        vector<int> v(t);
        for(int &j:v) cin >> j;
        sort(v.begin(),v.end());
        for(int j:v) {
            res+=seg.qry(j+1,sz-1);
            seg.update(j,1);
        }
    }
    cout << res;
    return 0;
}