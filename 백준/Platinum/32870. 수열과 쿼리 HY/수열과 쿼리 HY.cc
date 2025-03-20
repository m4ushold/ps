#include <bits/stdc++.h>
using namespace std;

int N, Q;
pair<int,int> A[303030];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=2;i<303030;i++) A[i] = {-1,-1};
    cin >> N >> Q;
    vector<int> v(N);
    int e=0,o=0,a=0,b=0,c=0;
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int m=2;m<=300'000;m++) {
        int mn=min(v[0]%m, v.back()%m), mx=max(v[0]%m,v.back()%m);
        for(int i=0;i<=v.back();i+=m) {
            int j=lower_bound(v.begin(),v.end(),i)-v.begin();
            if(0<=j-1) mn=min(mn,v[j-1]%m), mx=max(mx,v[j-1]%m);
            mn=min(mn,v[j]%m), mx=max(mx,v[j]%m);
            if(j+1<N) mn=min(mn,v[j+1]%m), mx=max(mx,v[j+1]%m);
        }
        A[m]={mn,mx};
    }
    for(int i=1,m;i<=Q;i++) cin >> m, cout << A[m].first << ' ' << A[m].second << '\n';
    return 0;
}