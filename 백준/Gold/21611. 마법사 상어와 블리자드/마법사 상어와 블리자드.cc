#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, A[55][55], B[55][55], C[5];
vector<pair<ll,ll>> dd({{0,-1}, {1,0}, {0,1}, {-1,0}}), dir({{-1,0}, {1,0}, {0,-1}, {0,1}});
vector<int> v;

bool chk(ll x, ll y) {return 1<=min(x,y) && max(x,y)<=N;}

void f() {
    ll x=N/2+1, y=N/2+1, d=0, r=0, a=1, cnt=0;
    while(cnt<N*N) {
        for(ll i=0;i<a;i++) {
            v.push_back(A[x][y]);
            B[x][y]=cnt++;
            x += dd[d].first, y += dd[d].second;
        }
        d=(d+1)%4;
        if(~d&1) a++;
    }
}

vector<pair<int,int>> comp() {
    vector<pair<int,int>> tmp;
    tmp.push_back({0,1});
    for(int i=1;i<v.size();i++) {
        if(tmp.back().first != v[i]) tmp.push_back({v[i],1});
        else tmp.back().second++;
    }
    return tmp;
}

int boom() {
    int cnt=0;
    auto cp=comp();
    v.clear();
    for(auto [n,m]:cp) {
        if(m>3) cnt++, C[n]+=m;
        else {
            for(int i=0;i<m;i++) v.push_back(n);
        }
    }
    return cnt;
}

void blizzard(int d, int s) {
    int x=N/2+1, y=N/2+1;
    for(int i=1;i<=s;i++) {
        x+=dir[d].first, y+=dir[d].second;
        if(chk(x,y)) {
            if(B[x][y]-i+1 < v.size()) v.erase(v.begin()+B[x][y]-i+1);
        }
        else break;
    }
    while(boom()) ;

    vector<pair<int,int>> tmp=comp();
    tmp.erase(tmp.begin());
    v.clear();
    v.push_back(0);
    for(auto [a,b]:tmp) {
        v.push_back(b), v.push_back(a);
        if(v.size() > N*N) {
            while(v.size() > N*N) v.pop_back();
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j];
    f();

    for(int i=0,d,s;i<M;i++) {
        cin >> d >> s;
        blizzard(d-1,s);
    }
    cout << C[1] + 2*C[2] + 3*C[3];
    return 0;
}