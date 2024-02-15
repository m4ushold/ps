#include <bits/stdc++.h>
using namespace std;

struct srk{ 
    int s, v, i; 
    srk() {s=v=i=0;}
    bool operator==(srk &b) {return s==b.s && v==b.v && i==b.i;}
    bool operator>(srk &b) {return s>=b.s && v>=b.v && i>=b.i;}
};

const int MAX_V=111;
int N, A[MAX_V], B[MAX_V], vi[MAX_V];
vector<int> G[MAX_V];
srk C[MAX_V];

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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<MAX_V;i++) A[i]=B[i]=-1;
    for(int i=0;i<N;i++) cin >> C[i].s >> C[i].v >> C[i].i;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
        if(C[i]==C[j] && i<j) G[i].push_back(j);
        else if(!(C[i]==C[j]) && C[i]>C[j]) G[i].push_back(j);
    }
    
    for(int i=0;i<N;i++) {
        memset(vi,0,sizeof vi), dfs(i);
        memset(vi,0,sizeof vi), dfs(i);
    }

    int cnt=0;
    for(int i=0;i<N;i++) cnt+=B[i]==-1;
    cout << cnt;
    return 0;
}