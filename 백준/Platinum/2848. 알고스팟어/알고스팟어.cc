#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int IN[202];
vector<int> G[202];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<string> v(n);
    set<int> s;
    for(auto &i:v) {
        cin>>i;
        for(char c:i) s.insert(c);
    }
    v.erase(unique(v.begin(),v.end()),v.end());
    n=v.size();


    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(v[i]!=v[j]) {
        int len=min(v[i].size(),v[j].size());
        if(v[i].substr(0,len)==v[j].substr(0,len) && v[i].size()>v[j].size()) {
            cout << '!';
            exit(0);
        }
        for(int k=0;k<len;k++) {
            if(v[i][k]!=v[j][k]) {
                G[v[i][k]].push_back(v[j][k]);
                IN[v[j][k]]++;
                break;
            }
        }
    }
    queue<int> q;
    for(int i:s) if(!IN[i]) q.push(i);
    string dap;
    while(q.size()) {
        int v=q.front(); q.pop();
        dap+=v;
        if(q.size()) {
            cout << "?";
            exit(0);
        }
        for(int i:G[v]) if(--IN[i] == 0) q.push(i);
    }
    if(dap.size()==s.size()) cout << dap;
    else cout << "!";
    
    return 0;
}