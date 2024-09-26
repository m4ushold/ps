#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a=0,b=0,l=-1;
    vector<int> c(10), d(10);
    for(int &i:c) cin >> i;
    for(int &i:d) cin >> i;
    for(int i=0;i<10;i++) {
        if(c[i]==d[i]) a++, b++;
        else if(c[i]>d[i]) a+=3, l=0;
        else b+=3, l=1;
    }
    cout << a << ' ' << b << '\n';
    if(a==10 && a==b) cout << 'D';
    else if(a==b) cout << (l?'B':'A');
    else if(a>b) cout << 'A';
    else cout << 'B';
    return 0;
}