#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; getline(cin,s);
    for(char c:s) {
        if(isupper(c)) cout << (char)((c-'A'+23)%26+'A');
        else if(islower(c)) cout << (char)((c-'a'+23)%26+'a');
        else cout << c;
    }
    return 0;
}