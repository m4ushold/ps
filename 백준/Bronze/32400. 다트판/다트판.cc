#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(20);
    for(int &i:v) cin >> i;
    int s=accumulate(v.begin(),v.end(),0), ss=0;
    int i=max_element(v.begin(),v.end())-v.begin();
    if(i==0) ss=v[i]+v[i+1]+v.back();
    else if(i==19) ss=v[i]+v[i-1]+v.front();
    else ss=v[i]+v[i-1]+v[i+1];
    s*=3, ss*=20;
    if(s==ss) cout << "Tie";
    else if(s>ss) cout << "Bob";
    else cout << "Alice";
    return 0;
}