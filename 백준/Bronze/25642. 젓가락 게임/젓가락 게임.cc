#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,b; cin >> a >> b;
    while(a<5 && b<5) {
        b+=a;
        if(b>=5) break;
        a+=b;
    }
    cout << (a >= 5 ? "yj" : "yt");
    return 0;
}