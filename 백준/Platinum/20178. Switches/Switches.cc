#include <bits/stdc++.h>
using namespace std;
using ll = long long;;

template<class T>
using Mat=vector<vector<T>>;

template<typename T>
tuple<Mat<T>,Mat<T>,int> Gauss(Mat<T> m) {
    int rank=0, r=m.size(), c=m.front().size();
    Mat<T> inv(r,vector<T>(c));
    if(r==c) for(int i=0;i<c;i++) inv[i][i]=T(1);
    for(int i=0;i<c;i++) {
        if(rank==r) break;
        if(m[rank][i]==T(0)) {
            int j=-1;
            for(int k=rank+1;k<r;k++) if(m[k][i]!=T(0)) {j=k; break;}
            if(j==-1 || m[j][i]==T(0)) continue;
            for(int k=0;k<c;k++) {
                m[rank][k]=m[rank][k]^m[j][k];
                inv[rank][k]=inv[rank][k]^inv[j][k];
            }
        }

        for(int j=0;j<r;j++) if(j!=rank && m[j][rank]) {
            for(int k=0;k<c;k++) {
                m[j][k]=m[j][k]^m[rank][k];
                inv[j][k]=inv[j][k]^inv[rank][k];
            }
        }
        rank++;
    }
    return {m,inv,rank};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Mat<int> m(n,vector<int>(n));

    for(auto &v:m) for(auto &i:v) cin >> i;

    auto [a,b,c]=Gauss(m);
    if(c<n) {cout << -1; return 0;}
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) if(b[i][j]) cout << j+1 << ' ';
        cout << '\n';
    }
    return 0;
}