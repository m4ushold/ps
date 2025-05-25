#include <bits/stdc++.h>
using namespace std;
using ll=long long;
 
ll N, A[1010101], B[1010101], S[1010101];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i];
    for(int i=1;i<=N;i++) S[i] = S[i-1] + (A[i]?1:-1)*B[i];
    
    vector<ll> v;
    for(int i=1;i<N;i++) v.push_back(S[N]-S[i]);
    sort(v.begin(),v.end(),greater<>());
 
    int cnt=1;
    for(ll i:v) if(i>0) S[N]+=i, cnt++;
    cout << cnt << ' ' << S[N];
    return 0;
}