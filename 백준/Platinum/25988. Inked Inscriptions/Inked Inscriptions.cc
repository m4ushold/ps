#include <bits/stdc++.h>
using namespace std;

int N, B;

struct Qry {
    int s, e;
    bool operator<(Qry &a) { 
        if(s/B == a.s/B) return (s/B)&1 ? e>a.e : e<a.e;
        return s < a.s; 
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N, B=sqrt(N);
    vector<Qry> v;
    for(int i=1,a;i<=N;i++) cin >> a, v.push_back({i,a});
    sort(v.begin(),v.end());
    for(auto [i,j]:v) cout << i << ' ' << j << '\n';
    return 0;
}