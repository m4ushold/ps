#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string str; cin >> str;
    int cnt=0,l=0,s=0;
    for(char c:str) {
        if(c=='L') l++;
        else if(c=='S') s++;
        else if(c=='R') {
            if(l>0) cnt++, l--;
            else break;
        } else if(c=='K') {
            if(s>0) cnt++, s--;
            else break;
        } else cnt++;
    }
    cout << cnt;
    return 0;
}