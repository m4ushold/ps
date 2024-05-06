#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int cnt=0;
    for(int b=1;b<=500;b++) for(int a=b;a<=500;a++) if(a*a-b*b==n) cnt++;
    cout << cnt;
    return 0;
}