#include <bits/stdc++.h>
using namespace std;

struct Seg2d {
    static const int sz=1<<11;
    struct {
        int T[sz<<1];
        void update(int i, int x) {
            T[i|=sz]=x;
            while(i>>=1) T[i]=T[i*2]+T[i*2+1];
        }
        int query(int l, int r) {
            int ret=0;
            for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
                if(l&1) ret=ret+T[l++];
                if(~r&1) ret=ret+T[r--];
            }
            return ret;
        }
    } T[sz<<1];
	void update(int x, int y, int v) {
		T[x|=sz].update(y, v);
		while(x>>=1) {
			T[x].update(y, T[x*2].query(y, y) + T[x*2+1].query(y, y));
		}
	}
	int query(int l, int r, int ll, int rr) {
        int ret=0;
        for(l|=sz,r|=sz;l<=r;l/=2,r/=2) {
            if(l&1) ret+=T[l++].query(ll,rr);
            if(~r&1) ret+=T[r--].query(ll,rr);
        }
        return ret;
	}
} seg;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) for(int j=1,a;j<=n;j++) cin >> a, seg.update(i,j,a);
    for(int i=0,op,a,b,c,d;i<m;i++) {
        cin >> op >> a >> b >> c;
        if(!op) seg.update(a,b,c);
        else cin >> d, cout << seg.query(a,c,b,d) << '\n';
    }
}