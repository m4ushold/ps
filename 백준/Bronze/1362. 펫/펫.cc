#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int o,w,n,tc=0;
    while(cin >> o >> w && o) {
        char op;
        int f=0;
        while(cin >> op >> n && op!='#') {
            if(f) continue;
            if(op=='F') w+=n;
            else w-=n;
            if(w<=0) f=1;
        }

        cout << ++tc << " ";
        if(w<=0) cout << "RIP\n";
        else if(o*0.5<w && w<2*o) cout << ":-)\n";
        else cout << ":-(\n";
    }
    return 0;
}