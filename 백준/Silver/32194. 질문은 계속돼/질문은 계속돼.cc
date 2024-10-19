#include <bits/stdc++.h>
using namespace std;

int N, A[202020];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    A[1]=1;
    for(int i=2,op,x,y;i<=N+1;i++) {
        cin >> op >> x >> y;
        if(op==1 && A[y]-A[x-1] == y-x+1) A[i]=1;
        else if(op==2 && A[y]-A[x-1] == 0) A[i]=1;
        cout << (A[i] ? "Yes\n" : "No\n");
        A[i]+=A[i-1];
    }
    return 0;
}