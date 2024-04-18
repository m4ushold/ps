#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    stack<pair<int,int>> stk;
    for(int i=0,a;i<n;i++) {
        cin >> a;
        while(!stk.empty() && stk.top().first<a) stk.pop();
        cout << (stk.empty() ? 0 : stk.top().second) << ' ';
        stk.push({a,i+1});
    }
    return 0;
}