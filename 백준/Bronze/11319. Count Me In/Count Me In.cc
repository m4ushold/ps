#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        int cnt=0, l=0;
        for(char c:s) {
            c = tolower(c);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
            if(isalpha(c)) l++;
        }
        cout << l-cnt << ' ' << cnt << '\n';
    }
    return 0;
}