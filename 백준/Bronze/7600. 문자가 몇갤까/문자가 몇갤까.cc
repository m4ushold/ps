#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    while(getline(cin, s) && s!="#") {
        set<char> st;
        for(char c:s) if(isalpha(c)) st.insert(tolower(c));
        cout << st.size() << "\n";
    }
    return 0;
}