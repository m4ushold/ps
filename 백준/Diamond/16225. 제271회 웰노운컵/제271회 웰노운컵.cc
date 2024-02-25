#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[202020], B[202020];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) cin >> A[i];
    for(int i=0;i<n;i++) cin >> B[i];
    for(int i=0;i<n;i++) v[i]={B[i],A[i]};
    sort(v.begin(),v.end());
 
    ll res=v[0].second;
    priority_queue<int> pq;
    
    for(int i=1;i<n/2;i++) {
        pq.push(v[i*2-1].second), pq.push(v[i*2].second);
        res+=pq.top(), pq.pop();
    }
    cout << res;
    return 0;
}