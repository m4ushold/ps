#include <bits/stdc++.h>
using namespace std;

int N, D[8];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> D[i];
    sort(D,D+N);
    int mx=0;
    do {
        int a=0;
        for(int i=1;i<N;i++) a+=abs(D[i-1]-D[i]);
        mx=max(mx,a);
    } while(next_permutation(D, D+N));
    cout << mx;
    return 0;
}