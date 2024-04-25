#include <bits/stdc++.h>
using namespace std;

int N, A[101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    int t,a; cin >> t;
    while(t--) cin >> a, A[a]--;
    for(int i=1;i<=N;i++) cout << (A[i]>=0 ? "no\n" : "yes\n");
    return 0;
}