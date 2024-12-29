#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    int ammo=0, saved=0;
    for(int i=1;i<=n;i++) {
        string op; cin >> op;
        if(op=="ammo") ammo+=k;
        else if(op=="save") saved = ammo;
        else if(op=="load") ammo = saved;
        else ammo--;
        cout << ammo << '\n';
    }
    return 0;
}