#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(9), a({100,100,200,200,300,300,400,400,500});
    for(int &i:v) cin >> i;
    for(int i=0;i<9;i++) if(v[i]>a[i]) {
        cout << "hacker";
        return 0;
    }
    cout << (accumulate(v.begin(), v.end(), 0)>=100 ? "draw" : "none");
    return 0;
}