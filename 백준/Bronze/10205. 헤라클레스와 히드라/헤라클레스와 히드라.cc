#include <bits/stdc++.h>
using namespace std;

void sol(int tc) {
    int n; cin >> n;
    string s; cin >> s;
    for(char c:s) {
        if(c=='c') n++;
        else n--;
    }
    cout << "Data Set " << tc << ":\n" << n << "\n\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}