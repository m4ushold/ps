#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    while(cin >> a >> b >> c >> d && (a||b||c||d)) {
        cout << c - b << ' ' << d - a  << '\n';
    }
    return 0;
}