#include <bits/stdc++.h>
using namespace std;

int N, A[2][101];

int idx(int n) {
    int res=0;
    for(int i=1;i<n;i++) {
        if(A[1][i]==n || A[0][i]==n) res=max(res,i);
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) A[0][i]=A[1][i]=N-i+1;
    vector<tuple<int,int,int>> res;
    for(int i=1;i<N;i++) {
        res.push_back({i, A[0][i], A[0][i+1]});
        swap(A[0][i], A[0][i+1]);
    }
    for(int i=N;i;i--) {
        int j=idx(i);
        if(!j) continue;

        int s=A[0][j]==i ? 0:1;
        for(int k=j+1;k<=i;k++) {
            if(A[0][k] < A[1][k]) {
                res.push_back({k-1, A[s][k-1], A[0][k]});
                swap(A[s][k-1], A[0][k]);
                s=0;
            } else {
                res.push_back({k-1, A[s][k-1], A[1][k]});
                swap(A[s][k-1], A[1][k]);
                s=1;
            }
        }
        
        j=idx(i);
        if(!j) continue;
        s=A[0][j]==i ? 0:1;
        for(int k=j+1;k<=i;k++) {
            if(A[0][k] < A[1][k]) {
                res.push_back({k-1, A[s][k-1], A[0][k]});
                swap(A[s][k-1], A[0][k]);
                s=0;
            } else {
                res.push_back({k-1, A[s][k-1], A[1][k]});
                swap(A[s][k-1], A[1][k]);
                s=1;
            }
        }
    }
    cout << res.size() << '\n';
    for(auto [a,b,c]:res) cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}