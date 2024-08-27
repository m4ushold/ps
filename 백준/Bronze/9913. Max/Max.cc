#include <bits/stdc++.h>
using namespace std;

int A[1010];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int a; cin >> a;
        A[a]++;
    }
    cout << *max_element(A, A+1010);
    return 0;
}