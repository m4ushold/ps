#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,x,y,a,b; cin >> n >> x >> y;
    a=y, b=y*2-x;
    for(int i=2;i<n;i++){
        x=y;
        cin>>y;
        a=2*y-a, b=max(2*y-b,y), swap(a,b);
    }
    cout << max(b-a+1,0);
    return 0;
}