#include <bits/stdc++.h>
using namespace std;

int N, M, A[10101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0,a,b;i<M;i++) cin >> a >> b, A[a]=i+1, A[b]=i+1;
    vector<int> v;
    for(int i=0;i<10101;i++) if(A[i]) v.push_back(A[i]);
    --N;
    N%=v.size();
    cout << v[N];
    return 0;
}