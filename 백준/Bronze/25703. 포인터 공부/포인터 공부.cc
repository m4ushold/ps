#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    cout << "int a;\n";
    string prev="a";
    for(int i=1;i<=n;i++) {
        string t;
        cout << "int " << string(i,'*');
        t="ptr";
        if(i!=1) t+=to_string(i);
        cout << t << " = &" << prev << ";\n";
        prev = t;
    }
	return 0;
}