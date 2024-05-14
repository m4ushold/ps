#include <bits/stdc++.h>
using namespace std;

int N, A[303][303], B[303][303];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> A[i][j], B[i][j]=1e9;
    for(int i=1;i<=N;i++) B[i][i]=0;
    
    vector<tuple<int,int,int>> v;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(i!=j) {
        int f=1;
        for(int k=1;k<=N;k++) if(k!=i && k!=j) {
            if(A[i][j]==A[i][k]+A[k][j]) {f=0; break;}
        }
        if(f) {
            B[i][j]=A[i][j];
            if(i<j) v.emplace_back(i,j,B[i][j]);
        }
    }

    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) B[i][j]=min(B[i][j],B[i][k]+B[k][j]);
        }
    }
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(A[i][j]!=B[i][j]) {cout << -1; return 0;}
    cout << v.size() << '\n';
    for(auto [i,j,k]:v) cout << i << ' ' << j << ' ' << k << '\n';
    return 0;
}