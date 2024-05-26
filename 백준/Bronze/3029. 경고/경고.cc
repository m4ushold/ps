#include <bits/stdc++.h>
using namespace std;

int h(string s) { return stoi(s.substr(0,2))*60*60+stoi(s.substr(3,2))*60+stoi(s.substr(6)); }

int main()
{
    // ios::sync_with_stdio(0); cin.tie(0);
    string a,b; cin >> a >> b;
    int t=(h(b)-h(a)+24*60*60)%(24*60*60);
    if(!t) t=24*60*60;
    printf("%02d:%02d:%02d",t/60/60,t/60%60,t%60%60);
    // cout << t/60/60 << ':' << t/60%60 << ':' << t%60%60;
    return 0;
}