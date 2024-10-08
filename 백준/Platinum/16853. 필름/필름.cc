#include <bits/stdc++.h>
using namespace std;

const int SZ=151515;
int N, M, C[SZ*2], CNT;
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

int getSCC() {
    for(int i=0;i<2*CNT;i++) if(!C[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(C[i]==-1) S.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

int n(int i) { return i&1?i-1:i+1; }
int idx(int i) {return i<0?-(i+1)*2:i*2-1;}

void addCNF(int s, int e) { // s or e
    s=idx(s), e=idx(e);
    G[n(s)].push_back(e), G[n(e)].push_back(s);
    R[e].push_back(n(s)), R[s].push_back(n(e));
}

bool f() {
    for(int i=0; i<CNT; i++) if(C[i*2]==C[i*2+1]) return 0;
    return 1;
}

map<string,int> m({
    {"WHITE", 7},
    {"RED", 4}, {"GREEN", 2}, {"BLUE", 1}, 
    {"PURPLE", 5}, {"YELLOW", 6}, {"CYAN", 3},
    {"BLACK", 0}
});

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    CNT = 3*N;
    for(int i=1,a,b;i<=M;i++) {
        string k,c,d; cin >> a >> b >> k >> c >> d;
        bool ar = m[c]&(1<<2), ag=m[c]&(1<<1), ab=m[c]&1;
        bool br = m[d]&(1<<2), bg=m[d]&(1<<1), bb=m[d]&1;
        if((!ar && br) || (!ag && bg) || (!ab && bb)) {
            cout << "THINKINGFACE\n";
            exit(0);
        }

        vector<tuple<int,int,int,int>> v({
            {ar,br,a*3-2,b*3-2},
            {ag,bg,a*3-1,b*3-1},
            {ab,bb,a*3,b*3},
        });

        for(auto [ray, res, aa, bb]:v) if(ray) {
            if(k=="L") { // or
                if(res) addCNF(aa,bb);
                else addCNF(-aa,-aa), addCNF(-bb,-bb);
            } else { // and
                if(res) addCNF(aa,aa), addCNF(bb,bb);
                else addCNF(-aa,-bb);
            }
        }
    }
    
    getSCC();
    cout << (f() ? "ALIEN" : "THINKINGFACE");
    return 0;
}