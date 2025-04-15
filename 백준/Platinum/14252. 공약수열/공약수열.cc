#include <bits/stdc++.h>
using namespace std;

const int sz=1<<17;
int S[sz];

bool chk(int a, int b) {
    for(int i=a+1;i<=b-1;i++) {
        if(gcd(a,i) == 1 && gcd(b,i) == 1) return 1;
    }
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=1;i<n;i++) {
        if(gcd(v[i-1],v[i]) == 1) continue;
        else if(chk(v[i-1],v[i])) ans++;
        else ans+=2;
    }
    cout << ans;
    return 0;
}