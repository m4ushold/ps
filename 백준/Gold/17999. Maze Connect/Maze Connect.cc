#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int R, C;
char A[2020][2020];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(A, '.', sizeof(A));
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> A[i-j+C][i+j];
            if(A[i-j+C][i+j]=='\\') A[i-j+C][i+j]='-';
            else if(A[i-j+C][i+j]=='/') A[i-j+C][i+j]='|';
            else A[i-j+C][i+j]='.';
        }
    }
    int n = R+C;
    vector<vector<int>>vis(n, vector<int>(n)), cnt(n, vector<int>(n)), jud(n, vector<int>(n));
    for(int s=0; s<n; s++){
        for(int e=0; e<n; e++)if(!vis[s][e] && A[s][e] == '.'){
            int i = 0, op = 1;
            for(auto [x, y] : {P(s, e-1), P(s, e+1), P(s-1, e), P(s+1, e)}){
                i++;
                if(x < 0 || x >= n || y < 0 || y >= n || vis[x][y])continue;
                if(i <= 2 && A[x][y] == '-')op = 0;
                if(2 < i && i <= 4 && A[x][y] == '|')op = 0;
            }
            if(!op)jud[s][e] = 1;
        }
    }
    queue<P>q; 
    for(auto [x, y] : {P(0, 0), P(0, n-1), P(n-1, 0), P(n-1, n-1)})if(A[x][y] == '.'){
        q.push({x, y});
        vis[x][y] = 1;
    }
    while(q.size()){
        auto [s, e] = q.front(); q.pop();
        for(auto [x, y] : {P(s, e-1), P(s, e+1), P(s-1, e), P(s+1, e)}){
            if(x < 0 || x >= n || y < 0 || y >= n || vis[x][y] || A[x][y] != '.' || jud[x][y])continue;
            q.push({x, y});
            vis[x][y] = 1;
        }
    }
    int ans = 0;
    for(int s=0; s<n; s++){
        for(int e=0; e<n; e++)if(!vis[s][e] && !jud[s][e] && A[s][e] == '.'){
            ans++;
            queue<P>Q; Q.push({s, e}); vis[s][e] = 1;
            while(Q.size()){
                auto [xi, yi] = Q.front(); Q.pop();
                A[xi][yi] = '+';
                for(auto [x, y] : {P(xi, yi-1), P(xi, yi+1), P(xi-1, yi), P(xi+1, yi)}){
                    if(x < 0 || x >= n || y < 0 || y >= n || vis[x][y] || A[x][y] != '.' || jud[x][y])continue;
                    Q.push({x, y});
                    vis[x][y] = 1;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}