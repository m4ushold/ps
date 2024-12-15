#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    deque<int> dq;
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int a; cin >> a;
        dq.push_back(a);
    }
    while(dq.front() > dq.back()) {
        dq.push_front(dq.back());
        dq.pop_back();
    }
    int p=-1, cnt=1;
    while(dq.size()) {
        if(dq.front() <= p) cnt++;
        p=dq.front();
        dq.pop_front();
    }
    cout << cnt;
    return 0;
}