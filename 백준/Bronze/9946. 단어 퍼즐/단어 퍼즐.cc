#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b; 
    int i=1;
    while(cin >> a >> b && a!="END") {
        sort(a.begin(),a.end()), sort(b.begin(),b.end());
        cout << "Case " << i++ << ": " << (a==b?"same\n":"different\n");
    }
    return 0;
}