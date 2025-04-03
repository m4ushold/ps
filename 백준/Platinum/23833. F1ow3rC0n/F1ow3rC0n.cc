#include <bits/stdc++.h>
using namespace std;

const int sz=1<<17;
struct {
    int T[sz<<1];
    void upd(int i, int x) {
        T[i|=sz]=x;
        while(i/=2) T[i]=T[i*2]+T[i*2+1];
    }
    int sum(int l, int r) {
        int res=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) res+=T[l++];
            if(~r&1) res+=T[r--];
        }
        return res;
    }
} seg;
int N, Q, A[sz];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=2;i<=N;i++) if(A[i]!=A[i-1]) seg.upd(i, 1);
    for(int i=0,a,b,c;i<Q;i++) {
        cin >> a >> b >> c;
        if(a==1) {
            cout << seg.sum(b+1,c) + 1 << '\n';
        } else {
            A[b] = c;
            if(1<b) seg.upd(b, A[b-1]!=A[b]);
            if(b<N) seg.upd(b+1, A[b+1]!=A[b]);
        }
    }
    return 0;
}