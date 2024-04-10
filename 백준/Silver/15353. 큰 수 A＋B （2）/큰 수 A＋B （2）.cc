#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b,c; cin >> a >> b;
    reverse(a.begin(),a.end()), reverse(b.begin(),b.end());
    if(a.size()>b.size()) swap(a,b);
    int carry=0;
    for(int i=0,t;i<min(a.size(),b.size());i++) {
        t=a[i]+b[i]-'0'*2+carry, carry = t/10;
        c+=t%10+'0';
    }
    for(int i=min(a.size(),b.size()),t;i<max(a.size(),b.size());i++) {
        t=b[i]-'0'+carry, carry = t/10;
        c+=t%10+'0';
    }
    if(carry) c+='1';
    reverse(c.begin(),c.end());
    cout << c;
    return 0;
}