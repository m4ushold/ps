#include <bits/stdc++.h>
using namespace std;

int N, A[55];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int dap=-1;
    cin >> N;
    for(int i=1,a;i<=N;i++) cin >> a, A[a]++;
    for(int i=0;i<=N;i++) if(i==A[i]) dap=i;
    cout << dap;
    return 0;
}