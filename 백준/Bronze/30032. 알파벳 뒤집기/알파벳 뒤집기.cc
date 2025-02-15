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

map<char, char> ud = {{'d','q'}, {'b','p'}, {'q','d'}, {'p','b'}};
map<char, char> lr = {{'d','b'}, {'b','d'}, {'q','p'}, {'p','q'}};

char f(char c, int d) {
    return d == 1 ? ud[c] : lr[c];
}

void sol(int tc) {
    int n,d; cin >> n >> d;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            char c; cin >> c;
            cout << f(c, d);
        }
        cout << '\n';
    }
}

int main() {
    fastio;
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}