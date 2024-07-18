#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<P>A(n); 
    for(auto &[a, b] : A){
        char op; cin >> a >> op >> b;
    }
    if(A[0].first + A[0].second > 21){cout << "error 1"; return 0;}
    for(auto &[a, b] : A){
        int op = (a + b + 1) / 2;
        if(op & 1)swap(a, b);
    }
    int ed = 0;
    for(int s=1; s<n; s++){
        auto [pa, pb] = A[s-1];
        if(pa == 11 || pb == 11)ed = 1;
        auto [a, b] = A[s];
        if(pa > a || pb > b || (ed && P(a, b) != P(pa, pb)) || (a + b > 21)){
            cout << "error " << s+1; return 0;
        }
    }
    cout << "ok";
}