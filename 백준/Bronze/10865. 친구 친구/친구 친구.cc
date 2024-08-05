#include <bits/stdc++.h>
using namespace std;

int N, M, A[101010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,a,b;i<M;i++) {
        cin >> a >> b;
        A[a]++, A[b]++;
    }
    for(int i=1;i<=N;i++) cout << A[i] << '\n';
    return 0;
}