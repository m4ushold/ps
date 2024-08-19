#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=998'244'353;
int N, A[505050], B[505050], I[505050];

bool chk(int i) {return 1<=i && i<=N;}

ll re(int al, int ar, int bl, int br) {
    if(A[al]!=B[br]) return 0;
    if(!chk(al) || !chk(ar) || !chk(bl) || !chk(br)) return 1;
    int sz=I[A[al+1]]-bl+1;
    if(al == ar) return 1;

    if(ar-al == sz) {
        if(A[al+1] == B[br-1]) {
            if(sz > 1) return 2 * re(al+1, al+sz, bl, bl+sz-1) % MOD;
            return 2;
        }
        return 0;
    }
    if(I[A[al+1]] < bl || br<I[A[al+1]]) return 0;
    return re(al+1, al+sz, bl, bl+sz-1) * re(al+sz+1,ar,bl+sz,br-1) % MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i], I[B[i]]=i;

    cout << re(1,N,1,N);
    return 0;
}