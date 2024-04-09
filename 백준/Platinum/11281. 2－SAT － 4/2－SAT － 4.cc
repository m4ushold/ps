#include <bits/stdc++.h>
using namespace std;
using p=pair<int,int>;

const int SZ=10101;
int N, M, C[SZ*2], A[SZ];
vector<int> G[SZ*2], R[SZ*2], V;
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

int getSCC()
{
    for(int i=0;i<2*N;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

int n(int i) { return i&1?i-1:i+1; }
int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,s,e;i<M;i++) {
        cin >> s >> e;
        s=idx(s), e=idx(e);
        G[n(s)].push_back(e), G[n(e)].push_back(s);
        R[e].push_back(n(s)), R[s].push_back(n(e));
    }
    getSCC();
    
    int f=1;
    for(int i=0; i<N; i++) f&=(C[i*2]!=C[i*2+1]);
    if(f) {
        cout << "1\n";
        memset(A,-1,sizeof A);

        vector<p> v;
        for(int i=0;i<2*N;i++) v.push_back({C[i],i});
        sort(v.begin(),v.end());

        for(int i=0,j;i<v.size();i++) {
            j=v[i].second;
            if(A[j/2]==-1) A[j/2]=!(j&1);
        }

        for(int i=0;i<N;i++) cout << A[i] << ' ';
        cout << '\n';
    } else cout << 0;
    return 0;
}