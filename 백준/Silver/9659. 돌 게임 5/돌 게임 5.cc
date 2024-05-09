#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, D[1010]={0,1,0,1};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cout << (N&1 ? "SK" : "CY");
    return 0;
}