#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    stack<int> s;
    for(int i=0,a;i<n;i++) {
        cin >> a;
        while(!s.empty() && s.top()<=a) s.pop();
        s.push(a);
    }
    cout << s.size();
    return 0;
}