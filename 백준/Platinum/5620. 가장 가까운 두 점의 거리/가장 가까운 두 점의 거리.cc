#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> p;

inline ll square(ll a) { return a*a; }
inline ll dist(const p& a, const p& b) { return square(a.x-b.x)+square(a.y-b.y); }

struct cmpY
{
    bool operator() (const p& a, const p& b) const {
        return tie(a.y,a.x) < tie(b.y,b.x);
    }
};

int N;
p A[505050], B[505050];

ll DnC(int l, int r)
{
    if (l==r) return LLONG_MAX;
    int m=(l+r)/2;
    ll xm=A[m].x, d=min(DnC(l, m), DnC(m+1,r));
    merge(A+l,A+m+1,A+m+1,A+r+1,B+l,cmpY());
    copy(B+l, B+r+1,A+l);

    vector<p> v;
    for(int i=l;i<=r;i++) if (square(A[i].x-xm) < d) v.push_back(A[i]);
    for(int i=0;i<v.size();i++) {
        for(int j=i-1;j>=0;j--) {
            if (square(v[i].y-v[j].y) < d) d = min(d, dist(v[i],v[j]));
            else break;
        }
    }

    return d;
}


int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i].x >> A[i].y;
    sort(A+1,A+N+1);

    cout << DnC(1, N) << '\n';
    return 0;
}