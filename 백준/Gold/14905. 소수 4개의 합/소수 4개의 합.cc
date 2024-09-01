#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int S[1010101]={1,1};

vector<int> sol(int n) {
    vector<int> v;
    if(n&1) v.push_back(2), v.push_back(3), n-=5;
    else v.push_back(2), v.push_back(2), n-=4;
    if(n<=0) return v;
    for(int i=2;i<n;i++) if(!S[i] && !S[n-i]) {v.push_back(i), v.push_back(n-i); break;}
    return v;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i*i<1010101;i++) if(!S[i]) for(int j=2*i;j<1010101;j+=i) S[j]=1;
    int n;
    while(cin >> n) {
        vector<int> v=sol(n);
        if(v.size()<4) cout << "Impossible.";
        else for(int i:v) cout << i << " ";
        cout << '\n';
    }
    return 0;
}