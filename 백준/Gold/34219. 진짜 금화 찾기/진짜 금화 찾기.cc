#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

void sol(int tc) {
    int n; cin >> n;
    int sum=0;
    cout << "? ";
    for(int i=0;i<n;i++) {
        cout << i%6 << ' ';
        sum += i%6;
    }
    cout << endl;
    int res; cin >> res;
    int a = res-sum*9;

    sum=0;
    cout << "? ";
    for(int i=0,j=0;i<n;i++) {
        if(i%6 == a) cout << j%6 << ' ', sum+=j%6, j++;
        else cout << 0 << ' ';
    }
    cout << endl;
    cin >> res;
    int b = res-sum*9;

    sum=0;
    cout << "? ";
    for(int i=0,j=0;i<n;i++) {
        if(i%36 == b*6+a) cout << j%6 << ' ', sum+=j%6, j++;
        else cout << 0 << ' ';
    }
    cout << endl;
    cin >> res;
    int c = res-sum*9;
    cout << "! " << c*36+b*6+a+1 << endl;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}