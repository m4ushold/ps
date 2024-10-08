#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[505][505];
vector<pair<ll,ll>> v({{0,-1}, {1,0}, {0,1}, {-1,0}});

bool chk(ll x, ll y) {return 1<=min(x,y) && max(x,y)<=N;}

void prllState() {
    for(ll i=1;i<=N;i++) {
        for(ll j=1;j<=N;j++) cout << A[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}

void wind(ll x, ll y, ll d) {
    // cout << x << ' ' << y << ", " << d << " : \n";
    // prllState();
    ll xx=x+v[d].first, yy=y+v[d].second;
    ll sand=0, tmp=0, tot=0;
    if(chk(xx,yy)) sand=A[xx][yy], A[xx][yy]=0;
    if(!sand) return;

    // 5%
    xx=x+v[d].first*3, yy=y+v[d].second*3, tmp = sand * 5 / 100;
    if(chk(xx,yy)) A[xx][yy] += tmp;
    tot+=tmp;

    if(v[d].first) { // ver
        // 10
        xx=x+v[d].first*2, yy=y, tmp = sand*10/100;
        if(chk(xx,yy+1)) A[xx][yy+1]+=tmp;
        if(chk(xx,yy-1)) A[xx][yy-1]+=tmp;
        tot+=2*tmp;
        // 7
        xx=x+v[d].first, yy=y, tmp = sand*7/100;
        if(chk(xx,yy+1)) A[xx][yy+1]+=tmp;
        if(chk(xx,yy-1)) A[xx][yy-1]+=tmp;
        tot+=2*tmp;
        // 2
        xx=x+v[d].first, yy=y, tmp = sand*2/100;
        if(chk(xx,yy+2)) A[xx][yy+2]+=tmp;
        if(chk(xx,yy-2)) A[xx][yy-2]+=tmp;
        tot+=2*tmp;
        // 1
        xx=x, yy=y, tmp = sand/100;
        if(chk(xx,yy+1)) A[xx][yy+1]+=tmp;
        if(chk(xx,yy-1)) A[xx][yy-1]+=tmp;
        tot+=2*tmp;
    } else { // hor
        // 10
        xx=x, yy=y+v[d].second*2, tmp = sand*10/100;
        if(chk(xx+1,yy)) A[xx+1][yy]+=tmp;
        if(chk(xx-1,yy)) A[xx-1][yy]+=tmp;
        tot+=2*tmp;
        // 7
        xx=x, yy=y+v[d].second, tmp = sand*7/100;
        if(chk(xx+1,yy)) A[xx+1][yy]+=tmp;
        if(chk(xx-1,yy)) A[xx-1][yy]+=tmp;
        tot+=2*tmp;
        // 2
        xx=x, yy=y+v[d].second, tmp = sand*2/100;
        if(chk(xx+2,yy)) A[xx+2][yy]+=tmp;
        if(chk(xx-2,yy)) A[xx-2][yy]+=tmp;
        tot+=2*tmp;
        // 1
        xx=x, yy=y, tmp = sand/100;
        if(chk(xx+1,yy)) A[xx+1][yy]+=tmp;
        if(chk(xx-1,yy)) A[xx-1][yy]+=tmp;
        tot+=2*tmp;
    }
    
    // alpha
    xx=x+v[d].first*2, yy=y+v[d].second*2, tmp = sand - tot;
    if(chk(xx,yy)) A[xx][yy]+=tmp;
}

void f() {
    ll x=N/2+1, y=N/2+1, d=0, r=0, a=1, cnt=0;
    while(cnt<N*N) {
        for(ll i=0;i<a;i++) {
            wind(x,y,d);
            x += v[d].first, y += v[d].second;
            cnt++;
        }
        d=(d+1)%4;
        if(~d&1) a++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ll sum=0;
    for(ll i=1;i<=N;i++) for(ll j=1;j<=N;j++) cin >> A[i][j], sum+=A[i][j];
    f();
    for(ll i=1;i<=N;i++) for(ll j=1;j<=N;j++) sum-=A[i][j];
    cout << sum;
    return 0;
}