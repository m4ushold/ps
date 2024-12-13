#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int y=stoi(s.substr(0,4)), m=stoi(s.substr(5,2)), d=stoi(s.substr(8,2)), n;
    cin >> n;
    d+=n;
    while(d>30) {
        if(m==12) y++, m=0;
        m++, d-=30;
    }
    printf("%d-%02d-%02d\n",y,m,d);
    return 0;
}