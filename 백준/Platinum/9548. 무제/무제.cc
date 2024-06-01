#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        rope<char> r(s.c_str());
        while(cin >> s && s!="END") {
            int x,y;
            string p;
            if(s=="I") cin >> p >> x, r.insert(x,p.c_str());
            else cin >> x >> y, cout << r.substr(x,y-x+1) << '\n';
        }
    }
    return 0;
}