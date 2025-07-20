#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz = 1<<18;

int N, A[sz], L[sz], R[sz], I[sz];

bool f(int l, int r) {
    if(l>=r) return 1;
    int s=l, res=0;
    for(int i=0;i<=(r-l)/2;i++) {
        if(L[l+i]<l && r<R[l+i]) {
            res = f(l,l+i-1) && f(l+i+1,r);
            break;
        }
        if(L[r-i]<l && r<R[r-i]) {
            res = f(l,r-i-1) && f(r-i+1,r);
            break; 
        }
    }
    return res;
}

void sol() {
    cin >> N;
    vector<int> v;
    for(int i=1;i<=N;i++) cin >> A[i], v.push_back(A[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=N;i++) A[i] = lower_bound(v.begin(),v.end(),A[i])-v.begin();

    for(int i=0;i<=N;i++) I[i]=0;
    for(int i=1;i<=N;i++) L[i]=I[A[i]], I[A[i]]=i;
    for(int i=0;i<=N;i++) I[i]=N+1;
    for(int i=N;i;i--) R[i]=I[A[i]], I[A[i]]=i;

    if(f(1,N)) cout << "non-";
    cout << "boring\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--) sol();
    return 0;
}