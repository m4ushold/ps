#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    for(ll len=1;n>0;len++) {
        ll t = 26 + 26*25*(len-1);
        if(n < t) {
            int m = t/26, k = n-1;
            char a = k/m + 'a';
            k%=m;
            vector<tuple<char,char,int,int>> vec;
            for(char b='a';b<='z';b++) {
                if(a==b) vec.push_back({a,a,len,0});
                else {
                    for(int j=1;j<len;j++) vec.push_back({a,b,j,len-j});
                }
            }

            sort(vec.begin(),vec.end(),[](auto a, auto b){
                auto [aa, ab, ac, ad] = a;
                auto [ba, bb, bc, bd] = b;
                if(ac != bc) {
                    if(ac < bc) return ab < ba;
                    else return aa < bb;
                }
                return ab < bb;
            });
            
            auto [aa,bb,al,bl]=vec[k];
            cout << string(al,aa) << string(bl,bb) << '\n';
            break;
        } else n-=t;
    }
    return 0;
}