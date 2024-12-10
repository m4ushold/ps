#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n;
    while(cin >> n) {
        set<int> s;
        for(int i=1;i<1000;i++) {
            for(char c:to_string(n*i)) s.insert(c);
            if(s.size() == 10) {cout << i << "\n"; break;}
        }
    }
    return 0;
}