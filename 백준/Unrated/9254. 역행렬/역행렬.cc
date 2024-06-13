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
                m[rank][k]=m[rank][k]+m[j][k];
                if(r==c) inv[rank][k]=inv[rank][k]+inv[j][k];
            }
        }

        T l=T(1)/m[rank][i];
        for(int j=0;j<c;j++) {
            m[rank][j]=m[rank][j]*l;
            if(r==c) inv[rank][j]=inv[rank][j]*l;
        }
        for(int j=0;j<r;j++) {
            if(j==rank) continue;
            T a=m[j][i];
            for(int k=0;k<c;k++) {
                m[j][k]=m[j][k]-m[rank][k]*a;
                if(r==c) inv[j][k]=inv[j][k]-inv[rank][k]*a;
            }
        }
        rank++;
    }
    return {m,inv,rank};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    Mat<double> matrix(n,vector<double>(n));
    for(auto &i:matrix) for(auto &j:i) cin >> j;
    auto [mat, inv, rank]=Gauss(matrix);
    if(rank!=n) {cout << "no inverse\n"; return 0;}
    for(auto i:inv) {
        for(auto j:i) cout << fixed << setprecision(12) << j << ' ';
        cout << '\n';
    }
    return 0;
}