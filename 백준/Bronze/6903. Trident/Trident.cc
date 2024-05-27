#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c; cin >> a >> b >> c;
    for(int i=0;i<a;i++) cout << '*'+string(b,' ')+"*"+string(b,' ')+"*\n";
    cout << string(2*b+3,'*')+'\n';
    for(int i=0;i<c;i++) cout << string(b+1,' ')+"*\n";
    return 0;
}