#include <bits/stdc++.h>
using namespace std;

int N, A[202];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    string s; cin >> s;
    for(int i='A';i<'A'+N;i++) cin >> A[i];
    stack<double> stk;
    for(char c:s) {
        if(isupper(c)) stk.push(A[c]);
        else {
            double a=stk.top(); stk.pop();
            if(c=='+') stk.top()+=a;
            else if(c=='-') stk.top()-=a;
            else if(c=='*') stk.top()*=a;
            else if(c=='/') stk.top()/=a;
        }
    }
    cout << fixed << setprecision(2) << stk.top() << '\n';

    return 0;
}