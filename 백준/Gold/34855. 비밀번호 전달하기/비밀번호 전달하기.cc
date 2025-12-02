#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;
 
bool f(vector<int> &v, vector<int> &s, int x) {
    vector<int> a(6);
    for(int i=0;i<6;i++) {
        a[i]=(v[i]+x)%64;
        if(s[a[i]]) return 0;
    }
    for(int i:a) cout << i+1 << ' ';
    return 1;
}
 
void sol(int tc) {
    int t; cin >> t;
    vector<int> v(6), s(100);
    for(int &i:v) cin >> i, s[--i]=1;
 
    if(t==1) {
        for(int i=1;i<64;i++) if(f(v,s,i)) return;
    } else {
        for(int i=63;i;i--) if(f(v,s,i)) return;
    }
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}