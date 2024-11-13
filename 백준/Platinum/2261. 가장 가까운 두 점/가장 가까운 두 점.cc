#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;

int N;
pair<ll,ll> A[101010], B[101010];

ll dist(pair<ll,ll>& a, pair<ll,ll>& b) {
    ll dx=a.x-b.x, dy=a.y-b.y;
    return dx*dx+dy*dy; 
}

ll DnC(int l, int r) {
    if (l==r) return LLONG_MAX;
    int m=(l+r)/2;
    ll xm=A[m].x, d=min(DnC(l, m), DnC(m+1,r));
    merge(A+l,A+m+1,A+m+1,A+r+1,B+l,[&](const pair<ll,ll>& a, const pair<ll,ll>& b) {
        return tie(a.y,a.x) < tie(b.y,b.x);
    });
    copy(B+l, B+r+1,A+l);
    vector<pair<ll,ll>> v;
    for(int i=l;i<=r;i++) if ((A[i].x-xm)*(A[i].x-xm) < d) v.push_back(A[i]);
    for(int i=0;i<v.size();i++) {
        for(int j=i-1;j>=0;j--) {
            if ((v[i].y-v[j].y)*(v[i].y-v[j].y) < d) d = min(d, dist(v[i],v[j]));
            else break;
        }
    }
    return d;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i].x >> A[i].y;
    sort(A+1,A+N+1);

    cout << DnC(1, N) << '\n';
    return 0;
}