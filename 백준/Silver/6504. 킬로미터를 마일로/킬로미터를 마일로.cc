#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll F[50]={1,1};

void sol() {
    ll x, a=0; cin >> x;
    for(int i=29;i>1;i--) if(F[i]<=x) {
        x-=F[i];
        a+=F[i-1];
    }
    cout << a << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for(int i=2;i<30;i++) F[i]=F[i-1]+F[i-2];
    while(t--) sol();
    return 0;
}