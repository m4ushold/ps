#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    int a=0;
    for(char c:s) if(c=='C') a++;
    cout << a/(n-a+1) + (a%(n-a+1)!=0?1:0);
    return 0;
}