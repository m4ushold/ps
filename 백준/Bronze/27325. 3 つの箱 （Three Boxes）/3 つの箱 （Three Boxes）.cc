#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; string s;
    cin >> n >> s;
    int x=1, cnt=0;
    for(char c:s) {
        x=max(1,min(3,x+(c=='L' ? -1 : 1)));
        if(x==3) cnt++;
    }
    cout << cnt;
    return 0;
}