#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a=-1;
        for(int j=0;j<m;j++) {
            char c; cin >> c;
            if(c=='c') a=0;
            cout << a << ' ';
            if(a>=0) a++;
        }
        cout << '\n';
    }
    return 0;
}