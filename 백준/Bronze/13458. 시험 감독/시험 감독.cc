#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,b,c; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    cin >> b >> c;
    ll res=0;
    for(int i:v) {
        i-=b;
        res++;
        if(i>0) {
            res+=i/c;
            i%=c;
            if(i) res++;
        }
    }
    cout << res;
    return 0;
}