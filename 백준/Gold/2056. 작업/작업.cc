#include <bits/stdc++.h>
using namespace std;

int N, M, IN[10101], W[10101], D[10101];
vector<int> G[10101];

vector<int> tSort()
{
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=N;i++) if(!IN[i]) q.push(i), D[i]=W[i];
    while(!q.empty()) {
        int v=q.front(); q.pop();
        res.push_back(v);
        for(int i : G[v]) {
            IN[i]--;
            if (!IN[i]) q.push(i);
        }
    }
    return res;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,n,e;i<=N;i++) {
        cin >> W[i] >> IN[i];
        for(int j=0;j<IN[i];j++) cin >> e, G[e].push_back(i);
    }

    for(int i:tSort()) for(int j:G[i]) D[j]=max(D[j],D[i]+W[j]);
    cout << *max_element(D,D+N+1);
    return 0;
}