#include <bits/stdc++.h>
using namespace std;

int A[3030][3030];

tuple<int,int,int> f(int n, int x=0, int y=0) {
    if(n==1) return {A[x][y]==-1, !A[x][y], A[x][y]==1};
    n/=3;
    vector<pair<int,int>> v={{0,0},{0,n},{0,n*2},{n,0},{n,n},{n,2*n},{2*n,0},{2*n,n},{2*n,2*n}};
    int a=0,b=0,c=0;
    for(auto [i,j]:v) {
        auto [d,e,g]=f(n,x+i,y+j);
        a+=d, b+=e, c+=g;
    }
    if((a+b+c) == 9 && max({a,b,c}) == 9) return {a/9, b/9, c/9};
    return {a,b,c};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> A[i][j];
    auto [a,b,c]=f(n);
    cout << a << '\n' << b << '\n' << c;
    return 0;
}