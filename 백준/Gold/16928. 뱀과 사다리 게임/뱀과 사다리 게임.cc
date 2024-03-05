#include <bits/stdc++.h>
using namespace std;

int N, M, L[101], S[101], A[101];

int f() {
    queue<pair<int,int>> q;
    q.push({1,0});
    while(!q.empty()) {
        auto [n,d]=q.front(); q.pop();
        A[n]=d;
        if(n==100) break;
        for(int i=1;i<=6;i++) if(!A[n+i] && n+i<=100) {
            if(L[n+i]) q.push({L[n+i],d+1});
            else if(S[n+i]) q.push({S[n+i],d+1});
            else q.push({n+i,d+1});
        }
    }
    return A[100];
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,s,e;i<N;i++) cin >> s >> e, L[s]=e;
    for(int i=0,s,e;i<M;i++) cin >> s >> e, S[s]=e;
    cout << f();
    return 0;
}