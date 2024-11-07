#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N;
vector<int> A[20202];

ll dist(ll x, ll y, ll xx, ll yy) {
    ll dx=x-xx, dy=y-yy;
    return dx*dx+dy*dy;
}

bool chk(int a, int b, int c, int d) {
    return 0<=min({a,b,c,d}) && max({a,b,c,d})<=2e4;
}

bool has(int x, int y) {
    return binary_search(A[x].begin(),A[x].end(), y);
}

void sol() {
    for(int i=0;i<20202;i++) A[i].clear();
    cin >> N;
    vector<pair<int,int>> v(N);
    for(auto &[x,y]:v) cin >> x >> y, x+=1e4, y+=1e4, A[x].push_back(y);
    for(int i=0;i<20202;i++) sort(A[i].begin(),A[i].end());

    ll len=0;
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        auto [x,y]=v[i];
        auto [xx,yy]=v[j];
        ll a=xx-x, b=yy-y;
        if(chk(x-b, xx-b, y+a, yy+a) && has(x-b, y+a) && has(xx-b, yy+a)) len=max(len, dist(x,y,xx,yy));
        if(chk(y-a, yy-a, x+b, xx+b) && has(x+b, y-a) && has(xx+b, yy-a)) len=max(len, dist(x,y,xx,yy));
    }
    cout << len << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
	return 0;
}