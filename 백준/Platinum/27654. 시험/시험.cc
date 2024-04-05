#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using exam_t=pair<int,int>;

int N, X;
vector<exam_t> v;

bool f(double m) {
    sort(v.begin(),v.end(),[&m](exam_t a, exam_t b){
        return -a.second*m+a.first > -b.second*m+b.first;
    });
    ll p=0,q=0;
    for(int i=0;i<X;i++) p+=v[i].first, q+=v[i].second;
    return 1.0*p>=m*q;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> X;
    v.resize(N);
    for(auto &[p,q]:v) cin >> p >> q;

    double s=0,e=1;
    for(int i=0;i<55;i++) {
        double m=(s+e)/2;
        if(f(m)) s=m;
        else e=m;
    }
    cout << fixed << setprecision(12) << s;
    return 0;
}