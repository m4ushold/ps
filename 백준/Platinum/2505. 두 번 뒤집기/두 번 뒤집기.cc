#include <bits/stdc++.h>
using namespace std;

int N, A[10101], B[10101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i], B[i]=A[i];
    vector<pair<int,int>> dap;
    int f=0;
    for(int i=1;i<=N;i++) if(i!=A[i]) {
        int j=find(A+1,A+N+1,i)-A;
        reverse(A+i, A+1+j);
        dap.push_back({i,j});
        if(dap.size()>2) {
            for(int i=1;i<=N;i++) A[i]=B[i];
            dap.clear();
            f=1;
            break;
        }
    }
    if(f) for(int i=N;i>=1;i--) if(i!=A[i]) {
        int j=find(A+1,A+N+1,i)-A;
        reverse(A+j, A+1+i);
        dap.push_back({j,i});
    }

    while(dap.size()<2) dap.push_back({1,1});
    for(auto [i,j]:dap) cout << i << ' ' << j << '\n';
    return 0;
}