#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, S[2020202]={1,1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i*i<2020202;i++) if(!S[i]) for(int j=2*i;j<2020202;j+=i) S[j]=1;
    cin >> N >> M;
    for(int i=1;i<=M;i++) {
        int cnt=0;
        for(int j=i;j<=2'000'000;j+=M) {
            if(S[j]) {
                cnt++;
                if(cnt >= N) {
                    for(int k=j-N*M+M;k<=j;k+=M) cout << k << ' ';
                    return 0;
                }
            } else cnt=0;
        }
    }
    cout << -1;
    return 0;
}