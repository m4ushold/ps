#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a=0,b=0; cin >> n;
    for(int i=0,c;i<n;i++) cin >> c, c?++a:++b;
    cout << "Junhee is " << (a<b?"not ":"") << "cute!";
    return 0;
}