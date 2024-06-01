#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    vector<crope> ver;
    ver.push_back("");
    int n, d=0; cin >> n;
    for(int i=0,a,p,v,c;i<n;i++) {
        string s;
        cin >> a;

        if(a==1) {
            cin >> p >> s, p-=d;
            ver.push_back(ver.back()), ver.back().insert(p,s.c_str());
        }
        else if(a==2) {
            cin >> p >> c, p-=d, c-=d;
            ver.push_back(ver.back()), ver.back().erase(p-1,c);
        }
        else {
            cin >> v >> p >> c, v-=d, p-=d, c-=d;
            crope tmp = ver[v].substr(p-1,c);
            d+=count(tmp.begin(),tmp.end(),'c');
            cout << tmp << '\n';
        }
    }
    return 0;
}