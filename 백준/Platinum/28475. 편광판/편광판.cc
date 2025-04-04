#include <bits/stdc++.h>
using namespace std;

const int sz=1<<18;
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

bool chk(int a, int b) { return (a+2)%8 == b || (a+6)%8 == b; }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=2;i<=N;i++) if(chk(A[i-1], A[i])) seg.upd(i, 1);
    for(int i=0,a,b,c;i<Q;i++) {
        cin >> a >> b >> c;
        if(a==1) {
            A[b] = c;
            if(1<b) seg.upd(b, chk(A[b-1], A[b]));
            if(b<N) seg.upd(b+1, chk(A[b], A[b+1]));
        } else {
            if(seg.sum(b+1, c)) cout << "0\n";
            else cout << "1\n";
        }
    }
    return 0;
}