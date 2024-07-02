#include <bits/stdc++.h>
using namespace std;

vector<int> v(10);
void f(int n, int i) {
    while(n) v[n%10]+=i, n/=10;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int a=1,b,i; cin >> b;
    for(i=1;a<=b;i*=10,a/=10,b/=10) {
        while(a && a<=b && a%10!=0) f(a++, i);
        while(b && a<=b && b%10!=9) f(b--, i);
        
        if(a>b) break;
        for(int &j:v) j+=(b/10-a/10+1)*i;
    }
    for(int i:v) cout << i << ' ';
    return 0;
}