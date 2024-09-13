#include <bits/stdc++.h>
using namespace std;

int N, cnt, a, b;

void z(int n, int i, int j)
{
    if (n==1) return;
    if (i <= a && a < i+n/2 && j <= b && b < j+n/2) z(n/2, i, j);
    if (i <= a && a < i+n/2 && j+n/2 <= b && b < j+n) {cnt+=(n/2)*(n/2); z(n/2, i, j+n/2);}
    if (i+n/2 <= a && a < i+n && j <= b && b < j+n/2) {cnt+=(n/2)*(n/2)*2; z(n/2, i+n/2, j);}
    if (i+n/2 <= a && a < i+n && j+n/2 <= b && b < j+n) {cnt+=(n/2)*(n/2)*3; z(n/2, i+n/2, j+n/2);}
}

int main(void)
{
    cin >> N >> a >> b;
    z(1<<N, 0, 0);
    cout << cnt << '\n';
    return 0;
}
