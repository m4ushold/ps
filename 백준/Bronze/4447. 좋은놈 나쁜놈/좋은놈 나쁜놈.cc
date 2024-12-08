#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        int g=0, b=0;
        for(char c:s) {
            if(tolower(c)=='g') g++;
            if(tolower(c)=='b') b++;
        }
        cout << s << " is ";
        if(g==b) cout << "NEUTRAL\n";
        else if(g>b) cout << "GOOD\n";
        else cout << "A BADDY\n";
    }
    return 0;
}