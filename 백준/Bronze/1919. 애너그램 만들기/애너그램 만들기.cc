#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> a(202), b(202);
    string c,d; cin >> c >> d;
    for(char i:c) a[i]++;
    for(char i:d) b[i]++;
    int cnt=0;
    for(int i='a';i<='z';i++) cnt+=min(a[i],b[i])*2;
    cout << d.size()+c.size()-cnt;
    return 0;
}