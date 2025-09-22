#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
int N, A[22][22];
 
bool chk(int i, int j, int ii, int jj) {
    vector<int> v;
    for(int x=i;x<=ii;x++) for(int y=j;y<=jj;y++) v.push_back(A[x][y]);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) if(i+1!=v[i]) return 0;
    return 1;
}
 
void sol(int tc) {
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j];
 
    int ans=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) for(int ii=i;ii<=N;ii++) for(int jj=j;jj<=N;jj++) {
        ans+=chk(i,j,ii,jj);
    }
    cout << ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}