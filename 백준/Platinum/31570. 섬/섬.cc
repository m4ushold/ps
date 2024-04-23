#include "island.h"
#include <bits/stdc++.h>
using namespace std;
 
void construct_two_trees(int N, std::vector<int> U, std::vector<int> V){
    if(N==3) {
        add_vertex(0,1,2);
        report({{0,1},{1,2},{2,3}});
        report({{0,2},{0,3},{1,3}});
        return;
    }
    vector<array<int,2>> a, b;
    vector<int> d(N);
    for(int i=0;i<U.size();i++) {
        d[U[i]]++, d[V[i]]++;
        b.push_back(array<int,2>{U[i],V[i]});
    }
    int u=0,v=0,w=0;
    for(int i=0;i<N;i++) {
        if(d[i]) a.push_back(array<int,2>{i,(i+1)%N});
        else !u ? u=i : v=i;
    }
    a.push_back(array<int,2>{u,(u+1)%N});
    a.push_back(array<int,2>{N,(u+N-1)%N});
    b.push_back(array<int,2>{v,(v+1)%N});
    b.push_back(array<int,2>{u,N});
    b.push_back(array<int,2>{N,(u+1)%N});
    add_vertex(u,(u+1)%N,(u+N-1)%N);
    
    report(a), report(b);
}
