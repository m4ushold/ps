#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, A[1010101], l, r=1e6, h, s;

int main(void)
{
    cin >> N >> M;
    for(int i=0;i<N;i++) {cin >> A[i]; r=min(r, A[i]);}

    r*=M;
    while (l+1 < r) {
        h = (l+r)/2; s=0;
        for(int i=0;i<N;i++) s += h/A[i];
        if (s >= M) r = h;
        else l = h;
    }
    

    cout << l+1 << '\n';

    return 0;
}