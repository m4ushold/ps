#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    set<int> s;
    rope<int> r;
    for(int i=1;i<=2*m;i++) s.insert(i);
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        while(r.size()<=x) r.push_back(0);
        r.insert(x,i);
        auto it = s.lower_bound(x+1);
        if(it!=s.end()) r.erase(*it, 1), s.erase(it);
    }
    cout << r.size()-1 << '\n';
    for(int i=1;i<r.size();i++) cout << r[i] << ' ';
    return 0;
}