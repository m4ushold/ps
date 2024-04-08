#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

const int MAX_V=500'001;
vector<int> G[MAX_V*2]; 
int N, M, IN[MAX_V*2], LOW[MAX_V*2], VI[MAX_V*2], ID[MAX_V*2], A[MAX_V];

void tarjan(int n) {
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
    for(int i=0; i<2*n; i++) if(!IN[i]) dfs(i);
}

int n(int i) { return i&1?i-1:i+1; }
int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,a,b,sa,sb;i<N;i++) {
        cin >> a >> sa >> b >> sb;
        if(!sa) a=-a;
        if(!sb) b=-b;
        int s=idx(a), e=idx(b);
        G[n(s)].push_back(e), G[n(e)].push_back(s);
    }
    tarjan(M);
    
    int f=1;
    for(int i=0; i<M; i++) f&=(ID[i*2]!=ID[i*2+1]);
    if(f) {
        memset(A,-1,sizeof A);

        vector<Point> v;
        for(int i=0;i<2*M;i++) v.push_back({ID[i],i});
        sort(v.begin(),v.end(), greater<>());

        for(int i=0,j;i<v.size();i++) {
            j=v[i].second;
            if(A[j/2]==-1) A[j/2]=!(j&1);
        }
        for(int i=0;i<M;i++) cout << A[i] << '\n';
    } else cout << "IMPOSSIBLE";
    return 0;
}