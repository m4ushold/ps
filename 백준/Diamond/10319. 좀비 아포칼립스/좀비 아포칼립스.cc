#include <bits/stdc++.h>
using namespace std;

const int MAX_F=1<<30;
int N;

struct edge_t {
    int v,c,f;
    edge_t* rev;
    edge_t(int b, int c, int d=0) : v(b), c(c), f(d) {}
    int rem() {
        return c-f;
    }
    void add(int x) {
        f+=x;
        rev->f-=x;
    }
};
vector<edge_t*> G[1<<17];

void addEdge(int u, int v, int w) {
    edge_t *a = new edge_t(v,w), *b = new edge_t(u,0);
    a->rev = b, b->rev = a;
    G[u].push_back(a), G[v].push_back(b);
}

int mxf(int s, int t, int mx) {
    int mf=0;
    while(1) {
        vector<int> par((N+1)*101,-1);
        vector<edge_t*> path((N+1)*101);
        queue<int> q;
        q.push(s);
        while(!q.empty()) {
            int v=q.front(); q.pop();
            for(edge_t *e:G[v]) if(e->rem()>0 && par[e->v]==-1) {
                q.push(e->v), par[e->v]=v, path[e->v]=e;
                if(e->v==t) break;
            }
        }
        if(par[t]==-1) break;

        int mn=MAX_F;
        for(int i=t;i!=s;i=par[i]) mn=min(mn, path[i]->rem());
        for(int i=t;i!=s;i=par[i]) path[i]->add(mn);
        mf+=mn;
        if(mf >= mx) return mx;
    }
    return mf;
}

void sol() {
    for(int i=0;i<1<<17;i++) G[i].clear();
    int n,m,i,g,t,r;
    cin >> n >> i >> g >> t >> m;
    N=n;

    vector<int> hos(m);
    for(int &i:hos) {
        cin >> i;
        for(int j=0;j<=t;j++) addEdge(i*101 + j, 0, MAX_F);
    }
    cin >> r;
    for(int i=0,a,b,c,d;i<r;i++) {
        cin >> a >> b >> c >> d;
        for(int j=0;j+d<=t;j++) {
            addEdge(a*101+j,b*101+j+d,c);
        }
    }
    for(int i=1;i<=n;i++) for(int j=0;j<t;j++) {
        addEdge(i*101+j,i*101+j+1,MAX_F);
    }
    cout << mxf(i*101, 0, g) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}