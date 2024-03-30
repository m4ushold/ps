#include <bits/stdc++.h>
using namespace std;
using ll=long long;

bool chk(vector<int> &v) {
    for(int i=0;i<5;i++) if(v[i]!=i+1) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(5);
    for(int &i:v) cin >> i;
    while(chk(v)) {
        for(int i=0;i<4;i++) if(v[i]>v[i+1]) {
            swap(v[i],v[i+1]);
            for(int k:v) cout << k << ' ';
            cout << '\n';
        }
    }
    
    return 0;
}