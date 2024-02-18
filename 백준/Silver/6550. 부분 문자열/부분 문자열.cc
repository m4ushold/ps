#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b;
    while(cin >> a >> b) {
        int i=0,j=0;
        while(i<a.size() && j<b.size()) {
            while(a[i]!=b[j] && j<b.size()) ++j;
            if(j<b.size() && a[i]==b[j]) ++i, ++j;
        }
        cout << (i==a.size() ? "Yes\n":"No\n");
    }
    return 0;
}