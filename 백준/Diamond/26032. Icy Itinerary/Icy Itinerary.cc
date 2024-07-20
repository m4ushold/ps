#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int,int> G[303030];

void add(list<int> &path, int v) {
    if(path.size()<2) {path.push_back(v); return;}
    
    auto a=*path.begin(), b=*(--path.end());
    if(G[a][v]) path.push_front(v);
    else if(!G[b][v]) path.push_back(v);
    else if(G[a][b]) path.push_front(b), path.pop_back(), path.push_front(v);
    else path.push_back(a), path.pop_front(), path.push_back(v);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,a,b;i<M;i++) cin >> a >> b, G[a][b]=1, G[b][a]=1;

    list<int> path;
    for(int i=2;i<=N;i++) add(path, i);
    add(path, 1);
    if(*path.begin() != 1) reverse(path.begin(),path.end());

    for(int i:path) cout << i << ' ';
    return 0;
}