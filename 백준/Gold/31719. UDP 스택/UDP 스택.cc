#include <bits/stdc++.h>
using namespace std;

struct stk {
    int t, b;
    void clear() {t=b=0;}
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for(int &i:v) cin >> i;
        stk u,d,p; // sorted u
        u.clear(), d.clear(), p.clear();
        for(int i:v) {
            if(u.t+1==i) {
                u.t++;
                if(u.t+1==d.b) u.t=d.t, d.clear();
                if(u.t+1==p.b) u.t=p.t, p.clear();
                if(u.t+1==d.b) u.t=d.t, d.clear();
            }
            else if(d.t+1==i) d.t++;
            else if(p.t+1==i) p.t++;
            else if(!d.b) d.b=d.t=i;
            else if(!p.b) p.b=p.t=i;
            else break;
        }

        // cout << u.b << ' ' << u.t << ' ' << d.b << ' ' << d.t << ' ' << p.b << ' ' << p.t << endl;
        cout << (u.t==n ? "YES\n" : "NO\n");
    }
    return 0;
}