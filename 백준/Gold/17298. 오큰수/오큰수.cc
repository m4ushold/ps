#include <bits/stdc++.h>
using namespace std;

int N, A[1010101];

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];
    stack<int> s;
    vector<int> v;
    for(int i=N-1;i>=0;i--) {
        while(!s.empty() && s.top() <= A[i]) s.pop();
        if (s.empty()) v.push_back(-1);
        else v.push_back(s.top());
        s.push(A[i]);
    }
    for(int i=N-1;i>=0;i--) cout << v[i] << ' ';
    cout << '\n';

    return 0;
}