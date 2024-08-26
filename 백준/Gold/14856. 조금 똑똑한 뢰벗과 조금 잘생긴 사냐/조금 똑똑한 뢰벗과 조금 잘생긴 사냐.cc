#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<int> ans;
ll F[101]={0,1}, S[101]={0,1};

void f(int i, ll a, vector<int> &tmp) {
    if(a==0) {
        if(ans.size() < tmp.size()) ans=tmp;
        return;
    }
    if(S[i]<a || i<0) return;

    if(i) f(i-1,a, tmp);
    if(F[i] <= a && i>1) {
        tmp.push_back(i);
        f(i-2, a-F[i], tmp);
        tmp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    int len=0;
    for(int i=2;F[i-1]<=n;i++) F[i]=F[i-1]+F[i-2], ++len;

    for(int i=2;i<=len;i++) S[i]+=S[i-2]+F[i];

    vector<int> tmp;
    f(len, n, tmp);

    if(ans.size()) {
        cout << ans.size() << '\n';
        sort(ans.begin(),ans.end());
        for(int i:ans) cout << F[i] << ' ';
    } else cout << -1;
    return 0;
}