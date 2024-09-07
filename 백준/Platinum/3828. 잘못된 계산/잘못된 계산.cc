#include <bits/stdc++.h>
using namespace std;
using lf=long double;

template<class T>
using Mat=vector<vector<T>>;

template<typename T>
tuple<Mat<T>,Mat<T>,int,T> Gauss(Mat<T> m) {
    int rank=0, r=m.size(), c=m.front().size();
    T det=T(1);
    Mat<T> inv(r,vector<T>(c));
    if(r==c) for(int i=0;i<c;i++) inv[i][i]=T(1);
    for(int i=0;i<c;i++) {
        if(rank==r) break;
        if(m[rank][i]==T(0)) {
            int j=-1;
            for(int k=rank+1;k<r;k++) if(m[k][i]!=T(0)) {j=k; break;}
            if(j==-1 || m[j][i]==T(0)) { det=T(0); continue;}
            for(int k=0;k<c;k++) {
                m[rank][k]=m[rank][k]+m[j][k];
                if(r==c) inv[rank][k]=inv[rank][k]+inv[j][k];
            }
        }

        det=det*m[rank][i];
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
    return {m,inv,rank,det};
}

int pw(int a, int n) {
    int r=1;
    for(int i=0;i<n;i++) r*=a;
    return r;
}

int test(int a, lf b, vector<lf> &coef) {
    lf r=1, f=0;
    for(auto i:coef) f+=r*i, r*=a;
    return abs(f-b) <= 1e-5;
}

void sol(int n) {
    vector<lf> v(n+3);
    for(auto &i:v) cin >> i;

    for(int i=0;i<n+3;i++) for(int j=i+1;j<n+3;j++) { // except for i and j
        Mat<lf> mat;
        for(int k=0;k<n+3;k++) if(k!=i && k!=j) {
            mat.emplace_back();
            for(int e=0;e<=n;e++) mat.back().push_back(pw(k,e));
            mat.back().push_back(v[k]);
            auto [m,inv,rank,det]=Gauss(mat);
            vector<lf> coef;
            for(auto vec:m) coef.push_back(vec.back());

            // test i,j
            if(test(i, v[i], coef)) {cout << j << '\n'; return;}
            if(test(j, v[j], coef)) {cout << i << '\n'; return;};
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int d;
    while(cin >> d && d) sol(d);
    return 0;
}