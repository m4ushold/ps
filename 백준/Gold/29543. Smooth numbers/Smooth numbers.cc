#include <bits/stdc++.h>
using namespace std;

int N, A[]={0,9,99,989,9889,97679,976679,9643469,96433469};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    cout << (N<9 ? A[N] : -1);
    return 0;
}