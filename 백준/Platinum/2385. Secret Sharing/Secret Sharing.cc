#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<string> a,b;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        s[0]=='0' ? a.push_back(s) : b.push_back(s);
    }    
    sort(a.begin(),a.end(),[](auto a, auto b){ return a+b < b+a; });
    sort(b.begin(),b.end(),[](auto a, auto b){ return a+b < b+a; });
    string t;
    for(auto i:a) t+=i;

    if(b.empty()) cout << "INVALID";
    else {
        int idx=min_element(b.begin(),b.end(),[&t](auto a, auto b){ return a+t+b<b+t+a; }) - b.begin();
        cout << b[idx] << t;
        for(int i=0;i<b.size();i++) if(i^idx) cout << b[i];
    }
    return 0;
}