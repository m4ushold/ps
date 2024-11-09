#include <bits/stdc++.h>
using namespace std;

int N, A, B, S[101010]={1,1};

int main() {
    cin.tie(0);
    for(int i=2;i<101010;i++) if(!S[i]) for(int j=2*i;j<101010;j+=i) S[j]=i;
    cin >> A >> B;
    int dap=0;
    for(int i=A;i<=B;i++) {
        int t=i, cnt=1;
        while(S[t]) cnt++, t/=S[t];
        if(!S[cnt]) dap++;
    }
    cout << dap;
    return 0;
}