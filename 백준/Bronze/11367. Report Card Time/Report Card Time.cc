#include <bits/stdc++.h>
using namespace std;

string f(int g) {
    if (g >= 97 && g <= 100) {
        return "A+";
    } else if (g >= 90 && g <= 96) {
        return "A";
    } else if (g >= 87 && g <= 89) {
        return "B+";
    } else if (g >= 80 && g <= 86) {
        return "B";
    } else if (g >= 77 && g <= 79) {
        return "C+";
    } else if (g >= 70 && g <= 76) {
        return "C";
    } else if (g >= 67 && g <= 69) {
        return "D+";
    } else if (g >= 60 && g <= 66) {
        return "D";
    } else {
        return "F";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<string, int>> v(n);
    for(auto &[i,j]:v) cin >> i >> j;
    for(auto [i,j]:v) cout << i << " " << f(j) << '\n';
    return 0;
}