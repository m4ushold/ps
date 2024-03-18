#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b; cin >> a >> b;
    for(char &c:a) if(c=='6') c='5';
    for(char &c:b) if(c=='6') c='5';
    cout << stoi(a)+stoi(b) << ' ';
    for(char &c:a) if(c=='5') c='6';
    for(char &c:b) if(c=='5') c='6';
    cout << stoi(a)+stoi(b);

    return 0;
}