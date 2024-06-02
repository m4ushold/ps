#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    int m, q;
    string s;
    cin >> m >> s;
    rope<char> r(s.c_str());
    cin >> q;
    for(int i=0,a,b,c;i<q;i++) {
        cin >> a >> b >> c;
        r.insert(c, r.substr(a,b-a));
        int n=r.size();
        r.erase(m, n-m+1);
    }
    cout << r;
    return 0;
}