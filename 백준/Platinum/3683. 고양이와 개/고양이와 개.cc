#include <bits/stdc++.h>
using namespace std;

const int MAX_V=4040;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V], C, D;
vector<int> G[MAX_V];

bool dfs(int v) 
{
    vi[v]=1;
    for(int i:G[v]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int matching() {
    int cnt=0;
    for(int i=1;i<=N;i++) {
        for(int i=0;i<MAX_V;i++) vi[i]=0;
        cnt+=dfs(i);
    }
    return cnt;
}

int toN(string s) {
    if(s[0]=='C') return stoi(s.substr(1));
    else return C+stoi(s.substr(1));
}

void sol() {
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1, G[i].clear();
    cin >> C >> D >> N;
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++) {
        string a,b; cin >> a >> b;
        v.push_back({toN(a), toN(b)});
    }

    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++) {
        if(v[i].first==v[j].second || v[i].second==v[j].first) {
            if(v[i].first <= C) G[i+1].push_back(j+1);
            else G[j+1].push_back(i+1);
        }
    }
    
    cout << N - matching() << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}