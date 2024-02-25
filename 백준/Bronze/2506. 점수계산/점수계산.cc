#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int t=0;
    for(int i=0,g=1,a;i<n;i++) {
        cin >> a;
        if(a) t+=g, ++g;
        else g=1;
    }
    cout << t;

    return 0;
}