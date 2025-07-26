#include <bits/stdc++.h>
using namespace std;
int N, A[100000];

int divconq(int l, int r)
{
    if (l>r) return 0;
    if (l==r) return A[l];
    int m = (l+r)/2, ll=m-1, rr=m+1, mn=A[m], cnt=1, res=A[m];
    while(l<=ll && rr<=r) {
        if(A[ll] > A[rr]) mn = min(mn, A[ll--]);
        else mn = min(mn, A[rr++]);
        res = max(res, mn*(++cnt));
    }
    while (l<=ll) {mn = min(mn, A[ll--]); res = max(res, mn*(++cnt));}
    while (rr<=r) {mn = min(mn, A[rr++]); res = max(res, mn*(++cnt));}
    res = max(divconq(l, m-1), res);
    res = max(divconq(m+1, r), res);
    return res;
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    cout << divconq(0, N-1) << '\n';
    return 0;
}