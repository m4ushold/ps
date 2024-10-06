#include <bits/stdc++.h>
using namespace std;

const int SZ=101010;
int N, M, C[SZ*2], A[SZ*2];
vector<int> G[SZ*2], R[SZ*2], V, SW[SZ*2];
vector<vector<int>> S;

void dfs1(int v)
{
    C[v]=-1;
    for(auto i:G[v]) if(!C[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c)
{
    C[v]=c; S.back().push_back(v);
    for(auto i:R[v]) if(C[i]==-1) dfs2(i,c);
}

int getSCC() {
    for(int i=0;i<2*M;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

int n(int i) { return i&1?i-1:i+1; }
int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

void addCNF(int s, int e) { // s->e
    s=idx(s), e=idx(e);
    G[n(s)].push_back(e), G[n(e)].push_back(s);
    R[e].push_back(n(s)), R[s].push_back(n(e));
}

bool f() {
    for(int i=0; i<M; i++) if(C[i*2]==C[i*2+1]) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1,n,a;i<=M;i++) {
        cin >> n;
        while(n--) {
            cin >> a;
            SW[a].push_back(i);
        }
    }
    for(int i=1;i<=N;i++) {
        int a=SW[i][0], b=SW[i][1];
        if(A[i]) { // light on
            // (a and b) or (!a and !b)
            // ((a or !a) and (a or !b)) and ((b or !a)and (b or !b))
            // (a or !b) and (b or !a)
            addCNF(a,-b), addCNF(b,-a);
        } else { // light off
            // (!a and b) or (a and !b)
            // (!a or (a and !b)) and (b or (a and !b))
            // (!a or !b) and (b or a)
            addCNF(a,b), addCNF(-a,-b);
        }
    }
    
    getSCC();
    cout << f();
    return 0;
}