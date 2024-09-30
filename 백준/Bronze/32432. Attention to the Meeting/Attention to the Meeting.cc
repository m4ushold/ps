#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define ll __int128_t
#define all(v) v.begin(), v.end()
using namespace std;

//int N, A[55][55];
//
//void rotate() {
//
//}
//bool chk() {
//    for(int i=1;i<=N;i++) for(int j=2;j<=N;j++) {
//        if(A[i][j]>A[i][j-1])
//    }
//    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++)
//}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    cin >> N;
//    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
//        cin >> A[i][j];
//    }
    int n, k;
    cin >> n >> k;
    cout << (k - (n - 1)) / n << endl;
}