#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
#define x first
#define y second
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
 
int N, M, X[111][2];
double D[111][2];
 
int ccw(pll a, pll b, pll c) {
    ll res=a.x*b.y+b.x*c.y+c.x*a.y;
    res-=b.x*a.y+c.x*b.y+a.x*c.y;
    return (res>0)-(res<0);
}
 
bool cross(pll a, pll b, pll c, pll d) {
    int ab=ccw(a,b,c)*ccw(a,b,d);
    int cd=ccw(c,d,a)*ccw(c,d,b);
    if(ab==0||cd==0) {
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return !(b<c||d<a);
    }
    return ab<=0&&cd<=0;
}
 
bool chk(int l, int r, int p, int q) {
    pll s={l,p}, e={r,q};
    for(int i=l+1;i<r;i++) {
        pll ss={i,X[i][0]}, ee={i,X[i][1]};
        if(!cross(s,e,ss,ee)) return 0;
    }
    return 1;
}
 
void sol(int tc) {
    cin >> M >> N;
    for(int i=1;i<=N;i++) cin >> X[i][0] >> X[i][1];
 
    for(int i=1;i<=N+1;i++) D[i][0]=D[i][1]=1e18;
 
    for(int i=1;i<=N+1;i++) {
        for(int j=0;j<i;j++) {
            if(chk(j,i,X[j][0],X[i][0])) D[i][0] = min(D[i][0], D[j][0] + hypot(j-i,X[i][0]-X[j][0]));
            if(chk(j,i,X[j][1],X[i][0])) D[i][0] = min(D[i][0], D[j][1] + hypot(j-i,X[i][0]-X[j][1]));
            if(chk(j,i,X[j][0],X[i][1])) D[i][1] = min(D[i][1], D[j][0] + hypot(j-i,X[i][1]-X[j][0]));
            if(chk(j,i,X[j][1],X[i][1])) D[i][1] = min(D[i][1], D[j][1] + hypot(j-i,X[i][1]-X[j][1]));
        }
    }
    cout << fixed << setprecision(12) << min(D[N+1][0], D[N+1][1]);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}