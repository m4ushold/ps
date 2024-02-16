#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> n >> m;
    deque<int> dq;
    for(int i=1;i<=n;i++) dq.push_back(i);
    int res=0;
    for(int i=0,x;i<m;i++) {
        cin >> x;
        deque<int> a=dq, b=dq;
        int cnta=0, cntb=0;
        while(a.front()!=x) a.push_back(a.front()), a.pop_front(), ++cnta;
        while(b.front()!=x) b.push_front(b.back()), b.pop_back(), ++cntb;
        if(cnta<cntb) dq=a, res+=cnta;
        else dq=b, res+=cntb;

        if(dq.front()==x) dq.pop_front();
        else dq.pop_back();
    }
    cout << res;
    return 0;
}