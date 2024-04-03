#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using box_t=tuple<int,int,int>;

int N, Q;
ll x=1, y=1, res=0;
vector<ll> X[202020], Y[202020], XX[202020], YY[202020];

bool cmp(box_t a, box_t b) {
    return get<1>(a)==get<1>(b) ? get<0>(a)<get<0>(b) : get<1>(a)<get<1>(b);
}

int g(int l, int f) {
    if(f) return upper_bound(X[x].begin(),X[x].end(),l)-X[x].begin()-1;
    else return upper_bound(Y[y].begin(),Y[y].end(),l)-Y[y].begin()-1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    vector<box_t> v(N);
    for(auto &[a,b,c]:v) cin >> a >> b >> c;
    sort(v.begin(),v.end());
    for(auto [x,y,w]:v) {
        if(Y[y].empty()) Y[y].push_back(0), YY[y].push_back(0);
        Y[y].push_back(x), YY[y].push_back(YY[y].back()+w);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto [x,y,w]:v) {
        if(X[x].empty()) X[x].push_back(0), XX[x].push_back(0);
        X[x].push_back(y), XX[x].push_back(XX[x].back()+w);
    }

    for(int i=0,d,v,l,r;i<Q;i++) {
        cin >> d >> v;
        if(d==0) l=x, r=x+v, x+=v;
        else if(d==1) l=y, r=y+v, y+=v;
        else if(d==2) l=x-v-1, r=x-1, x-=v;
        else if(d==3) l=y-v-1, r=y-1, y-=v;

        if(d&1 && !X[x].empty()) {
            l=g(l,1), r=g(r,1);
            res+=XX[x][r]-XX[x][l];
        } else if(~d&1 && !Y[y].empty()) {
            l=g(l,0), r=g(r,0);
            res+=YY[y][r]-YY[y][l];
        }
    }
    cout << res;
    return 0;
}