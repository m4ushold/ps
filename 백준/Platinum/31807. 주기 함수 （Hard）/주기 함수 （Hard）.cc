#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> GetFail(const vector<ll> &p){
    int n = p.size();
    vector<int> fail(n);
    for(int i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    ll L; cin >> L;
    vector<ll> v(L), s(L+1);
    for(ll &i:v) cin >> i;
    ll p=L-GetFail(v)[L-1],a,b;
    cin >> a >> b;
    for(ll i=1;i<=L;i++) s[i]+=s[i-1]+v[i-1];
    ll t=b-a;
    a=(a%p+p)%p, b=a+t;
    cout << b/p*s[p]+s[b%p] - a/p*s[p]-s[a%p];
    return 0;
}