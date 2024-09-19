#include <bits/stdc++.h>
using namespace std;

int N, M, K, T[101010], D[101010], IN[101010];
vector<int> G[101010], R[101010], DAG[101010];

void dijk() {
    for(int i=1;i<=N;i++) D[i]=INT_MAX/2;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,1}), D[1]=0;
    while(pq.size()) {
        auto [c,v]=pq.top(); pq.pop();
        for(int i:G[v]) {
            if(D[i]>D[v]+T[v]) {
                D[i]=D[v]+T[v];
                pq.push({D[i],i});
                R[i].clear(), R[i].push_back(v);
            } else if(D[i]==D[v]+T[v]) {
                R[i].push_back(v);
            }
        }
    }
}

vector<int> ts() {
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=N;i++) if(!IN[i]) q.push(i);
    while(!q.empty()) {
        int v=q.front(); q.pop();
        res.push_back(v);
        for(int i : DAG[v]) {
            IN[i]--;
            if (!IN[i]) q.push(i);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1;i<=N;i++) cin >> T[i];
    for(int i=0,s,e;i<M;i++) cin >> s >> e, G[s].push_back(e), G[e].push_back(s);

    if(N==2 && K==1) return cout << "impossible", 0;
    dijk();
    for(int i=1;i<=N;i++) for(int j:R[i]) DAG[j].push_back(i), IN[i]++;
    vector<int> v=ts();
    if(*max_element(G[1].begin(),G[1].end()) == N) {
        v.erase(max_element(v.begin(),v.end()));
        v.insert(v.begin(),N);
    }
    string s(N, 'N');
    char a='N', b='S';
    if(K<N-K) K=N-K, swap(a,b);
    for(int i:v) {
        if(K>0) s[i-1]=a, K--;
        else s[i-1]=b;
    }
    cout << s;
    return 0;
}