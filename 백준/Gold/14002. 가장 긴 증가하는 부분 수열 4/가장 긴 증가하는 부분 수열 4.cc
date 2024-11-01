#include <bits/stdc++.h>
using namespace std;

int N, A[1010], dp[1010], P[1010]={-1,}, r, a;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];

    for(int i=1;i<=N;i++) {
        dp[i]=1;
        for(int j=1;j<=N;j++) {
            if (A[j]<A[i]) {
                if (dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    P[i] = j;
                }
            }
        }
    }

    for(int i=1;i<=N;i++) {
        if (r < dp[i]) { r=dp[i]; a=i; }
    }

    cout << r << '\n';
    
    vector<int> v;
    while(a) { v.push_back(A[a]); a=P[a]; }
    for(int i=v.size()-1;i>=0;i--) cout << v[i] << ' ';
    cout << '\n';


    return 0;
}