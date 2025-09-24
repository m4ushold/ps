#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, M, B[1010][1010];
char A[1010][1010];

bool chk(int x) {
    for(int j=1;j<=M;j++) {
        int cnt=0;
        for(int i=1;i<=N;i++) {
            if(B[i][j] >= x) cnt++;
            else cnt=0;

            if(cnt >= x) return 1;
        }
    }
    return 0;
}

void sol(int tc) {
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> A[i][j];
            if(A[i][j]!=A[i][j-1]) B[i][j]=1;
            else B[i][j]=B[i][j-1]+1;
        }
    }

    int l=1, r=min(N, M);
    while(l<r) {
        int m=l+r+1>>1;
        if(chk(m)) l=m;
        else r=m-1;
    }
    cout << l*l;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}