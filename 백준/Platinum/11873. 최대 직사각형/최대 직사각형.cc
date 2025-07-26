#include <bits/stdc++.h>
using namespace std;

int N, M, A[1010][1010];

int dnc(int i, int l, int r) {
    if (l>r) return 0;
    if (l==r) return A[i][l];
    int m = (l+r)/2, ll=m-1, rr=m+1, mn=A[i][m], cnt=1, res=A[i][m];
    while(l<=ll && rr<=r) {
        if(A[i][ll] > A[i][rr]) mn = min(mn, A[i][ll--]);
        else mn = min(mn, A[i][rr++]);
        res = max(res, mn*(++cnt));
    }
    while (l<=ll) {mn = min(mn, A[i][ll--]); res = max(res, mn*(++cnt));}
    while (rr<=r) {mn = min(mn, A[i][rr++]); res = max(res, mn*(++cnt));}
    res = max(dnc(i, l, m-1), res);
    res = max(dnc(i, m+1, r), res);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while(cin >> N >> M && N) {
        int mx=0;
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                cin >> A[i][j];
                if(A[i-1][j]!=0 && A[i][j]) A[i][j]+=A[i-1][j];
            }
            mx = max(mx, dnc(i, 1, M));
        }
        cout << mx << '\n';
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) A[i][j]=0;
    }
    return 0;
}