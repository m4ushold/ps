#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void sol(int tc) {
    string cmd;
    getline(cin, cmd);
    int n = stoi(cmd), idx=0;
    vector<string> v;
    while(n--) {
        getline(cin, cmd);
        if(cmd.substr(0,3) == "Run") {
            v.push_back(cmd.substr(4));
            idx=v.size()-1;
        } else {
            int cnt=0;
            for(char c:cmd) if(c=='+') cnt++;
            idx=cnt%v.size();
        }
        v.insert(v.begin(),v[idx]);
        v.erase(v.begin()+idx+1);
        cout << v.front() << '\n';
    }
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}