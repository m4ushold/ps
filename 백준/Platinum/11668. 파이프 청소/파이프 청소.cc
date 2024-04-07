#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using ll=long long;
using Point=pair<ll,ll>;

int N, M, A[1010], C[1010];
Point W[1010], P[1010];
vector<int> G[1010];

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

bool isBipartite() {
    for(int i=1;i<=M;i++) if(!C[i]) {
        stack<int> st;
        st.push(i), C[i]=1;

        while(!st.empty()) {
            int v = st.top(); st.pop();
            for(int j:G[v]) {
                if(!C[j]) {
                    C[j] = -C[v];
                    st.push(j);
                } else if(C[j]==C[v]) return 0;
            }
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> W[i].x >> W[i].y;
    for(int i=1;i<=M;i++) cin >> A[i] >> P[i].x >> P[i].y;
    for(int i=1;i<=M;i++) for(int j=i+1;j<=M;j++) if(A[i]!=A[j] && cross(W[A[i]], P[i], W[A[j]], P[j])) {
        G[i].push_back(j), G[j].push_back(i);
    }
    
    cout << (isBipartite()?"possible":"impossible");
    return 0;
}