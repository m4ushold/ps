#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin >> n >> s;

    int t=0, e=0;
    for(char c:s) c=='2' ? t++ : e++;
    if(t==e) cout << "yee";
    else if(t > e) cout << 2;
    else cout << 'e';
    return 0;
}