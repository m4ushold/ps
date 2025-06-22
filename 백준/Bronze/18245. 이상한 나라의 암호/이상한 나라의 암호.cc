#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s;
    int tc=2;
    while(getline(cin, s) && s!="Was it a cat I saw?") {
        for(int i=0;i<s.size();i+=tc) cout << s[i];
        cout << "\n";
        tc++;
    }
    return 0;
}