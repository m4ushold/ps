#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, A[1010101], l, r, h, s;

int main(void)
{
    cin >> N >> M;
    for(int i=0;i<N;i++) {cin >> A[i]; r=max(r, A[i]);}

    while (l < r) {
        h = (l+r+1)/2; s=0;
        for(int i=0;i<N;i++) s += A[i]/h;
        if (s < M) r = h-1;
        else l = h;
    }

    cout << l << '\n';

    return 0;
}