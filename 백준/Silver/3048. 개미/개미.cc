#include <bits/stdc++.h>
using namespace std;

int N, M, T;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    string a,b; cin >> a >> b;
    reverse(a.begin(),a.end());
    vector<pair<char,int>> v;
    for(char c:a) v.push_back({c,0});
    for(char c:b) v.push_back({c,1});
    cin >> T;
    while(T--) {
        for(int i=0;i<v.size()-1;i++) if(!v[i].second) {
            if(v[i+1].second) swap(v[i], v[i+1]), i++;
        }
    }
    for(auto [c,d]:v) cout << c;
    return 0;
}