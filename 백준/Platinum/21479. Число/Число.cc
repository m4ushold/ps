#include <bits/stdc++.h>
using namespace std;

bool cmp(string &a, string &b) {
    return a+b > b+a;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<string> v;
    string s;
    while(cin >> s) v.push_back(s);
    sort(v.begin(),v.end(),cmp);
    for(auto i:v) cout << i;
    return 0;
}