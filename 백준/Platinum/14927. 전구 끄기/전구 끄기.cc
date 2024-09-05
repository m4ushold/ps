#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, A[22][22], B[22][22], C;
vector<pair<int,int>> v={{0,0},{1,0},{-1,0},{0,1},{0,-1}};

bool bound(int x, int y) {return 0<=min(x,y) && max(x,y)<N;}
void flip(int x, int y) {for(auto [i,j]:v) if(bound(x+i,y+j)) A[x+i][y+j]^=1;}
void init() { C=0; for(int i=0;i<N;i++) for(int j=0;j<N;j++) A[i][j]=B[i][j]; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> B[i][j];

    int mn=1e9;
    for(int i=0;i<(1<<N);i++) {
        init();
        for(int j=0;j<N;j++) if((i>>j)&1) flip(0,j), C++;
        for(int j=1;j<N;j++) for(int k=0;k<N;k++) if(A[j-1][k]) flip(j,k), C++;
        if(*max_element(A[N-1], A[N-1]+N) == 0) mn=min(mn,C);
    }
    if(mn>=1e9) cout << -1;
    else cout << mn;
    return 0;
}