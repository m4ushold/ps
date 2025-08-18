#include <bits/stdc++.h>
using namespace std;
using ll=long long;

char A[3][101];

void sol(int tc) {
    int n,j,s,h,k; cin >> n >> j >> s >> h >> k;
    for(int i=0;i<3;i++) for(int ii=0;ii<n;ii++) cin >> A[i][ii];

    int a=0,b=0,c=0;
    for(int i=0;i<n;i++) {
        if(A[0][i] == '.' && A[1][i] == '.' && A[2][i] == '^') a++;
        else if(A[0][i] == '.' && A[1][i] == '^' && A[2][i] == '^') b++;
        else if(A[0][i] == 'v') c++;
    }

    c=max(c-s,0);
    if(a>j) a-=j;
    else j-=a, a=0, b-=j/2;
    b=max(b,0);

    h-=(a+b+c)*k;
    if(h<=0) cout << -1;
    else cout << h;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}