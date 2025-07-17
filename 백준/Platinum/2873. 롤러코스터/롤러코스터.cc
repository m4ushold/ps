#include <bits/stdc++.h>
using namespace std;

int N, M, A[1010][1010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) cin >> A[i][j];

    if(N&1) {
        for(int i=1;i<=N;i++) {
            if(i&1) cout << string(M-1, 'R');
            else cout << string(M-1, 'L');
            if(i<N) cout << "D";
        }
    } else if(M&1) {
        for(int i=1;i<=M;i++) {
            if(i&1) cout << string(N-1, 'D');
            else cout << string(N-1, 'U');
            if(i<M) cout << 'R';
        }
    } else {
        int x,y,mn=1e9;
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
            if(((i+j)&1) && mn > A[i][j]) mn=A[i][j], x=i, y=j;
        }
        for(int i=1;i<=(x-1)/2*2;i++) {
            if(i&1) cout << string(M-1, 'R');
            else cout << string(M-1, 'L');
            cout << "D";
        }
        for(int i=1;i<y;i++) {
            if(i&1) cout << "DR";
            else cout << "UR";
        }
        for(int i=y;i<M;i++) {
            if(i&1) cout << "RD";
            else cout << "RU";
        }
        for(int i=1;i<=N-(x-1)/2*2-2;i++) {
            cout << 'D';
            if(i&1) cout << string(M-1, 'L');
            else cout << string(M-1, 'R');
        }
    }
    return 0;
}