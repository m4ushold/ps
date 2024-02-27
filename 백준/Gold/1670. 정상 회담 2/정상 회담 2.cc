#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=987654321;
ll N, A[5050]={1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<5050;i++) for(int k=0;k<i;k++) A[i]=(A[i]+A[k]*A[i-k-1]%MOD)%MOD;
    cin >> N;
    cout << A[N/2] << '\n';
    return 0;
}