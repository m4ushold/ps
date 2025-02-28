#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
#define all(v) v.begin(),v.end()
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end());

using namespace std;
using ll = long long;

// PBDS
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>;

// rope
#include <ext/rope> 
using namespace __gnu_cxx; // SGI extension

void sol(int tc) {
    int n; cin >> n;
    map<char,int> m;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        m[s[0]]=1;
    }
    int cnt=0;
    for(int i='A';i<='A'+n;i++) {
        if(m[i]==0) break;
        cnt+=m[i];
    }
    cout << cnt;
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}