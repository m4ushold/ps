#include <bits/stdc++.h>
using namespace std;

int A[10101], N, M, sum, cnt;

int main(void)
{
    cin >> N >> M;
    for (int i=1;i<=N;i++) cin >> A[i];
    
    for (int i=1,j=1;i<=N;sum-=A[i++]) {
        while(sum < M) sum+=A[j++];
        if (sum == M) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}