#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
#define x first
#define y second
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
int CCW(const P &a,const P &b,const P &c){
	ll ret = a.x*b.y + b.x*c.y + c.x*a.y;
	ret   -= b.x*a.y + c.x*b.y + a.x*c.y;
	return (ret>0) - (ret<0);
}
ll len(const P &a,const P &b){
	ll dx = a.x-b.x,dy = a.y-b.y;
	return dx*dx + dy*dy;
}
vector<P> ConvexHull(vector<P>poly){
	swap(poly[0], *min_element(poly.begin(), poly.end()));
	sort(poly.begin()+1, poly.end(), [&](const P &a,const P &b){
		int d = CCW(poly[0], a, b);
		if(d)return d > 0;
		return len(poly[0], a) < len(poly[0], b);
	});
	vector<P>S, tmp;
	for(const auto &p : poly){
		while(S.size() > 1 && CCW(S[S.size()-2], S.back(), p) <= 0)S.pop_back();
		S.push_back(p);
	}
    for(auto c : tmp)S.push_back(c);
	return S;
}
bool checkIn(const vector<P>&con,const P &a){
	if(con.size() < 3)return false;
	if(CCW(con[0], con[1], a) < 0)return false;
	int L = 1, R = con.size()-1;
	while(L < R){
		int M = (L+R+1) >> 1;
		if(CCW(con[0], con[M], a) >= 0)L = M;
		else R = M-1;
	}
    if(L == con.size()-1)return false;
    if(L == 1)return CCW(con[L], con[L+1], a) > 0 && CCW(con[0], con[L], a) > 0;
	return CCW(con[L], con[L+1], a) > 0;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, cnt = 0; cin >> n;
    vector<P>in(n);
    map<P, int>id;
    for(auto &[x, y] : in)cin >> x >> y, id[{x, y}] = ++cnt;
    auto poly = ConvexHull(in);
    vector<int>ans;
    for(auto [x, y] : in){
        if(!checkIn(poly, P(x, y)))ans.push_back(id[{x, y}]);
    }
    sort(all(ans));
    for(int i : ans)cout << i << " ";
}