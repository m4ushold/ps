#include <bits/stdc++.h>
using namespace std;

const int sz=55;
int N, M, ID[sz], A[sz][sz];
vector<int> G[sz], R[sz], V;
vector<vector<int>> SCC;

void dfs1(int v) {
    ID[v]=-1;
    for(auto i:G[v]) if(!ID[i]) dfs1(i);
    V.push_back(v);
}

void dfs2(int v, int c) {
    ID[v]=c; SCC.back().push_back(v);
    for(auto i:R[v]) if(ID[i]==-1) dfs2(i,c);
}

int getSCC() {
    for(int i=1;i<=N;i++) if(!ID[i]) dfs1(i);
    reverse(V.begin(),V.end());
    int cnt=0;
    for(auto i:V) if(ID[i]==-1) SCC.emplace_back(), dfs2(i,++cnt);
    return cnt;
}

bool f(int l, int r) {
    memset(ID, 0, sizeof(ID));
    for(int i=1;i<=N;i++) G[i].clear(), R[i].clear();
    V.clear(), SCC.clear();

    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        if(i!=j && l<=A[i][j] && A[i][j]<=r) {
            G[i].push_back(j), R[j].push_back(i);
        }
    }
    return getSCC() == 1;
}

vector<int> v;
bool chk(int x) {
    int i=0,j=0;
    while(j<v.size()) {
        if(v[j]-v[i] <= x) {
            if(f(v[i], v[j])) return 1;
            j++;
            continue;
        }
        i++;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    if(N==1) return cout << 0, 0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
        cin >> A[i][j];
        if(i!=j) v.push_back(A[i][j]);
    }
    sort(v.begin(),v.end()), v.erase(unique(v.begin(),v.end()),v.end());

    int l=0, r=200'000;
    while(l<r) {
        int m=l+r>>1;
        if(chk(m)) r=m;
        else l=m+1;
    }
    cout << r;
    return 0;
}