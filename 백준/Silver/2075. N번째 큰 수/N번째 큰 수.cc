#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0,a;i<n*n;i++){
        cin >> a;
        pq.push(a);
        if (pq.size()>n) pq.pop();
    }
    cout << pq.top() << '\n';
    return 0;
}