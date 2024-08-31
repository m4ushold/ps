#include <bits/stdc++.h>
using namespace std;

int A[1010101], S[1010101]={1,1};

void sol() {
    memset(A, 0, sizeof(A));
    int n,a,b; cin >> n >> a >> b;
    queue<pair<int,int>> q; q.push({n,0});
    while(q.size()) {
        auto [v,c]=q.front(); q.pop();
        if(!S[v] && a<=v && v<=b) {cout << c << '\n'; return;}
        A[v]=1;
        if(!A[v/2]) q.push({v/2,c+1}), A[v/2]=1;
        if(!A[v/3]) q.push({v/3,c+1}), A[v/3]=1;
        if(v+1 <= b && !A[v+1]) q.push({v+1,c+1}), A[v+1]=1;
        if(a <= v-1 && !A[v-1]) q.push({v-1,c+1}), A[v-1]=1;
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i*i<1010101;i++) if(!S[i]) for(int j=2*i;j<1010101;j+=i) S[j]=1;
    int t; cin >> t;
    while(t--) sol();
    return 0;
}