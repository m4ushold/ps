#include <bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
int N, W, A[1010][1010];
p P[1010][1010];
vector<p> v;

int dist(int i, int j) { return abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second); }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> W;
    v.emplace_back(0,0), v.emplace_back(1,1), v.emplace_back(N,N);
    for(int i=0,a,b;i<W;i++) cin >> a >> b, v.emplace_back(a,b);

    for(int i=0;i<W+3;i++) for(int j=0;j<W+3;j++) A[i][j]=1e9;
    A[1][2]=0;

    for(int k=3,d;k<W+3;k++) {
        d=dist(k-1,k);
        for(int i=1;i<k;i++) {
            if(A[i][k]>A[i][k-1]+d) P[i][k]={i,k-1}, A[i][k]=A[i][k-1]+d;
            if(A[k][i]>A[k-1][i]+d) P[k][i]={k-1,i}, A[k][i]=A[k-1][i]+d;
            if(A[k][k-1]>A[i][k-1]+dist(i,k)) P[k][k-1]={i,k-1}, A[k][k-1]=A[i][k-1]+dist(i,k);
            if(A[k-1][k]>A[k-1][i]+dist(i,k)) P[k-1][k]={k-1,i}, A[k-1][k]=A[k-1][i]+dist(i,k);
        }
    }

    int ans=1e9,x,y;
    for(int i=1;i<W+3;i++) {
        if(ans>A[i][W+2]) ans=A[i][W+2],x=i,y=W+2;
        if(ans>A[W+2][i]) ans=A[W+2][i],x=W+2,y=i;
    }
    cout << ans << '\n';

    vector<int> a;
    a.push_back(x==W+2?1:2);
    while(x!=1||y!=2) {
        auto [i,j]=P[x][y];
        a.push_back(max(x,y)-1==i?1:2);
        x=i,y=j;
    }
    for(int i=a.size()-2;i>=0;i--) cout << a[i] << '\n';

    return 0;
}