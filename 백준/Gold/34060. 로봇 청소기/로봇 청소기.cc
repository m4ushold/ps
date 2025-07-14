#include <bits/stdc++.h>
using namespace std;

int N;
map<pair<int,int>,int> M;
vector<pair<int,int>> dir({
    {1,0}, {0,1}, {-1,0}, {0,-1}
});

int P[303030], S[303030];
void init(int n) { for(int i=1;i<303030;i++) P[i]=i,S[i]=1; }
int Find(int v) { return P[v]==v?v:P[v]=Find(P[v]); }
bool Union(int u, int v) {return (u=Find(u))!=(v=Find(v)) && (S[u]>S[v]?swap(u,v):void(), P[u]=v, S[v]+=S[u], true); }


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    init(1);
    vector<int> v(N);
    vector<pair<int,int>> cor;
    int prv=-10, x=1;
    for(int &i:v) {
        cin >> i;
        if(i <= prv) x++;
        cor.push_back({x,i});
        prv = i;
    }

    int cnt=1;
    for(auto [x,y]:cor) M[{x,y}] = cnt, cnt++;

    for(auto [x,y]:cor) {
        for(auto [dx,dy]:dir) {
            int ii = M[{x+dx,y+dy}];
            if(ii) Union(M[{x,y}], ii);
        }
    }

    cnt=0;
    for(int i=1;i<=N;i++) if(i == P[i]) cnt++;
    cout << cnt << '\n' << N;
    return 0;
}