#include <bits/stdc++.h>
using namespace std;
int N, M, V[9], A[9];

void recur(int l)
{
    if(l>=M) {
        for(int i=0;i<M;i++) cout << V[A[i]] << ' ';
        cout << '\n'; return;
    }

    for (int i=0;i<N;i++) {
        A[l] = i+1;
        recur(l+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> V[i];
    sort(V+1, V+N+1);
    recur(0);
    return 0;
}