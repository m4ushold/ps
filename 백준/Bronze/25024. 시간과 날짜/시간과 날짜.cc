#include <bits/stdc++.h>
using namespace std;

int A[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool a(int h, int m) {
    return (h >= 0 && h <= 23) && (m >= 0 && m <= 59);
}

bool b(int m, int d) {
    if (m < 1 || m > 12) return false;
    return (d >= 1 && d <= A[m - 1]);
}

void sol() {
    int x, y; cin >> x >> y;
    cout << (a(x,y) ? "Yes " : "No ") << (b(x,y) ? "Yes\n" : "No\n");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}