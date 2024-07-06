#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define prs(v) sort(all(v)); v.erase(unique(all(v)), v.end())
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
int d[111][111], A[111][111];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int s=1; s<=n; s++)for(int e=1; e<=n; e++)cin >> A[s][e], d[s][e] = A[s][e];
    for(int x=1; x<=n; x++)for(int s=1; s<=n; s++)for(int e=1; e<=n; e++){
        if(s ^ e){
            if(d[s][x] + d[x][e] < d[s][e])d[s][e] = d[s][x] + d[x][e];
        }
    }
    int ans = 0;
    for(int s=1; s<=n; s++)for(int e=s+1; e<=n; e++){
        if(d[s][e] != A[s][e]){
            cout << "-1\n"; return 0;
        }
        for(int x=1; x<=n; x++){
            if(s ^ x && e ^ x && d[s][x] + d[x][e] == d[s][e]){ans++; break;}
        }
    }
    cout << ans;
}