#include <bits/stdc++.h>
using namespace std;

vector<int> V;

int f(int mx, int n=0)
{
    if(mx < n) return 0;
    int ret=0;
    for(int i:V) {
        if(n*10+i <= mx) ret = max(ret, n*10+i);
        ret=max(ret,f(mx, n*10+i));
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n,s; cin >> n >> s;
    for(int i=0,a;i<s;i++) cin >> a, V.push_back(a);
    cout << f(n);
    return 0;
}