#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    // 소문자, 대문자, 숫자, 공백
    string s;
    while (getline(cin,s)) {
        int l=0,u=0,d=0,p=0;
        for(char c:s) {
            if(islower(c)) ++l;
            else if(isupper(c)) ++u;
            else if(isdigit(c)) ++d;
            else if(c==' ') ++p;
        }
        cout << l << ' ' << u << ' ' << d << ' ' << p << '\n';
    }
    return 0;
}