#include <bits/stdc++.h>
using namespace std;

const int sz=1<<17;
int N, M, IN[sz];
vector<int> G[sz], R[sz];

vector<int> tSort() {
    vector<int> res, q;
    set<int> s;
    for(int i=1;i<=N;i++) if (!IN[i]) q.push_back(i);
    
    while(!q.empty()) {
        vector<int> tmp;
        for(int v:q) {
            for(int i : G[v]) {
                IN[i]--;
                if(!IN[i]) tmp.push_back(i);
            }
            for(int i : R[v]) s.erase(i);
            s.insert(v);
        }
        if(s.size() == 1) res.push_back(*s.begin());
        q = tmp;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0,a, b;i<M;i++) cin >> a >> b, IN[b]++, G[a].push_back(b), R[b].push_back(a);
    vector<int> v=tSort();
    cout << v.size() << '\n';
    sort(v.begin(),v.end());
    for(int i:v) cout << i << ' ';
    return 0;
}