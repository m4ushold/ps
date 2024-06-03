#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    int t,cur=0; cin >> t;
    rope<char> r;
    for(int i=0,n;i<t;i++) {
        string op, s;
        cin >> op;
        if(op=="Move") cin >> n, cur=n;
        else if(op=="Insert") {
            char c;
            cin >> n;
            s="";
            for(int j=0;j<n;j++) {
                cin.get(c);
                if(c=='\n') j--;
                else s+=c;
            }
            r.insert(cur, s.c_str());
        }
        else if(op=="Delete") cin >> n, r.erase(cur, n);
        else if(op=="Get") cin >> n, cout << r.substr(cur, n) << '\n';
        else if(op=="Prev") cur=max(cur-1, 0);
        else if(op=="Next") cur=min(cur+1, (int)r.size());
    }
    return 0;
}