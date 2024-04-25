#include "island.h"
#include <bits/stdc++.h>
using namespace std;

void construct_two_trees(int N, std::vector<int> U, std::vector<int> V) {
    vector<int> d(N,2), l(N), r(N);
    for(int i=0;i<U.size();i++) d[U[i]]++, d[V[i]]++;
    vector<array<int,2>> a, b;
    queue<int> q;
    for(int i=0;i<N;i++) {
        if(d[i]==2) q.push(i);
        l[i]=(i-1+N)%N, r[i]=(i+1)%N;
    }

    int cnt=accumulate(d.begin(),d.end(),0);
    while(!q.empty()) {
        if(cnt==6) break;
        int v=q.front(); q.pop();
        if(d[v]!=2) continue;
        a.push_back(array<int,2>{v,l[v]});
        b.push_back(array<int,2>{v,r[v]});
        cnt-=4, d[l[v]]--, d[r[v]]--, d[v]=0;
        l[r[v]]=l[v], r[l[v]]=r[v];
        if(d[l[v]]==2) q.push(l[v]);
        if(d[r[v]]==2) q.push(r[v]);
    }

    vector<int> v;
    for(int i=0;i<N;i++) if(d[i]) v.push_back(i);

    add_vertex(v[0],v[1],v[2]);
    a.push_back(array<int,2>{v[0],v[1]});
    a.push_back(array<int,2>{v[1],N});
    a.push_back(array<int,2>{v[2],N});

    b.push_back(array<int,2>{v[0],N});
    b.push_back(array<int,2>{v[0],v[2]});
    b.push_back(array<int,2>{v[1],v[2]});

    report(a), report(b);
}