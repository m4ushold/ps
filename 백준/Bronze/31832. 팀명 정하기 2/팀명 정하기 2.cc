#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int u=0, l=0, d=0;
        for(char c:s) {
            if(isupper(c)) u++;
            if(islower(c)) l++;
            if(isdigit(c)) d++;
        }
 
        if(u <= l && s.size()<=10 && d!=s.size()) cout << s;
    }
    return 0;
}