#include <bits/stdc++.h>
using namespace std;

int N, M, IN[505], D[505], W[505];
vector<int> G[505];

vector<int> tSort()
{
    queue<int> q;
    vector<int> res;
    for(int i=1;i<=N;i++) if (!IN[i]) q.push(i);
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
    for(int i=1,a;i<=N;i++) {
        cin >> D[i], W[i]=D[i];
        while(cin >> a && a>0) G[a].push_back(i), ++IN[i];
    }
    vector<int> v=tSort();
    for(int i:v) {
        for(int j:G[i]) D[j]=max(D[j],D[i]+W[j]);
    }
    for(int i=1;i<=N;i++) cout << D[i] << '\n';
    return 0;
}