#include <bits/stdc++.h>

#define all(v) v.begin(),v.end()
#define int long long
using namespace std;
using ll = long long;

ll N, A[202020];


auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie();
    int n;
    cin >> n;
    vector<int> A(n + 1);
    A[0] = 1;
    for (int s = 1; s < n + 1; s++)A[s] = A[s - 1] + 2;
    vector<int> L, R;
    for (int s = 0; s <= (n + 1) / 2; s++)L.push_back(A[s]);
    for (int s = n; s > n / 2; s--)R.push_back(A[s]);
    int i = 0, j = 0;
    vector<int> ans(n + 10);
    ans[1] = 2;
    for (int s = 2; s <= n + 2; s += 2) {
        ans[s] = ans[s - 1] - L[i++];
        if (s + 1 <= n + 2)ans[s + 1] = ans[s] + R[j++];
    }
    for (int s = 1; s <= n + 2; s++)cout << ans[s] << " ";
}