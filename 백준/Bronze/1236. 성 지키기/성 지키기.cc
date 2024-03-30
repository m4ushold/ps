#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, M, R[55], C[55];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=N;i++) for(int j=1;j<=M;j++) {
        char c; cin >> c;
        if(c=='X') R[i]++, C[j]++;
    }
    int r=0,c=0;
    for(int i=1;i<=N;i++) if(!R[i]) r++;
    for(int i=1;i<=M;i++) if(!C[i]) c++;
    cout << max(r,c);

    return 0;
}