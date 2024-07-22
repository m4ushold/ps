#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(50);
    for(int &i:v) cin >> i;
    int a; cin >> a;
    int i=find(v.begin(),v.end(),a)-v.begin()+1;
    if(i<=5) cout << "A+";
    else if(i<=15) cout << "A0";
    else if(i<=30) cout << "B+";
    else if(i<=35) cout << "B0";
    else if(i<=45) cout << "C+";
    else if(i<=48) cout << "C0";
    else cout << "F";
    return 0;
}