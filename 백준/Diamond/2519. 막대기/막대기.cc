#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;
using LineSegment=pair<Point,Point>;
using Polygon=vector<Point>;

int ccw(const Point& a, const Point& b, const Point& c) {
    ll res=a.x*b.y+b.x*c.y+c.x*a.y;
    res-=b.x*a.y+c.x*b.y+a.x*c.y;
    return (res>0)-(res<0);
}


bool cross(Point& a, Point& b, Point& c, Point& d) {
    int ab=ccw(a,b,c)*ccw(a,b,d);
    int cd=ccw(c,d,a)*ccw(c,d,b);
    if(ab==0&&cd==0) {
        if(a>b) swap(a,b);
        if(c>d) swap(c,d);
        return !(b<c||d<a);
    }
    return ab<=0&&cd<=0;
}

struct TwoSat {
    const static int MAX_V=10101;
    vector<int> G[MAX_V*2];
    int CNT_V, IN[MAX_V*2], LOW[MAX_V*2], VI[MAX_V*2], ID[MAX_V*2];

    void clear() {
        memset(IN, 0, sizeof IN), memset(LOW, 0, sizeof LOW), memset(VI, 0, sizeof VI), memset(ID, 0, sizeof ID);
        for(int i=0;i<MAX_V*2;i++) G[i].clear();
    }

    void tarjan() {
        int c=0, scc=0;
        stack<int> s;
        function<void(int)> dfs=[&](int v) {
            IN[v]=LOW[v]=++c, VI[v]=1, s.push(v);
            for(auto i : G[v]) {
                if(!IN[i]) dfs(i), LOW[v]=min(LOW[v], LOW[i]); 
                else if(VI[i]) LOW[v]=min(LOW[v], IN[i]);
            }
            
            if(LOW[v]==IN[v]) {
                scc++;
                while(!s.empty()) {
                    int t=s.top(); s.pop(), ID[t]=scc, VI[t]=0;
                    if(v==t) break;
                }
            }
        };
        for(int i=0; i<2*CNT_V; i++) if(!IN[i]) dfs(i);
    }

    void addCNF(int a, int b) {
        a=idx(a), b=idx(b);
        G[n(a)].push_back(b), G[n(b)].push_back(a);
    }

    int n(int i) { return i&1?i-1:i+1; }
    int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

    bool satisfy() {
        tarjan();
        for(int i=0;i<CNT_V;i++) if(ID[i*2]==ID[i*2+1]) return 0;
        return 1;
    }

    vector<int> getVals() { // shuold call satisfy before
        vector<int> ret(CNT_V,-1);

        vector<pair<int,int>> v;
        for(int i=0;i<2*CNT_V;i++) v.push_back({ID[i],i});
        sort(v.begin(),v.end(), greater<>());

        for(auto [i,j]:v) if(ret[j/2]==-1) ret[j/2]=~j&1;
        return ret;
    }
} cnf;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cnf.CNT_V=3*n;
    vector<LineSegment> v(3*n);
    for(auto &[s,e]:v) cin >> s.x >> s.y >> e.x >> e.y;
    for(int i=0;i<n;i++) {
        int a=i*3+1, b=i*3+2, c=i*3+3;
        cnf.addCNF(a,b), cnf.addCNF(b,c), cnf.addCNF(a,c);
    }
    for(int i=0;i<3*n;i++) for(int j=i+1;j<3*n;j++) {
        if(cross(v[i].x, v[i].y ,v[j].x, v[j].y)) cnf.addCNF(-i-1, -j-1);
    }

    if(cnf.satisfy()) {
        vector<int> v=cnf.getVals();
        cout << 3*n-accumulate(v.begin(),v.end(),0) << '\n';
        for(int i=0;i<3*n;i++) if(!v[i]) cout << i+1 << ' ';
    } else cout << -1;

    return 0;
}