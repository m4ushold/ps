#include <bits/stdc++.h>
using namespace std;
 
int N, A[101];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=0,x;i<3*N;i++) cin >> x, A[x]++;
    
    int cnt=0;
    for(int i=1;i<=100;i++) for(int j=i+1;j<=100;j++) for(int k=j+1;k<=100;k++) {
        int f=0;
        A[i]++, A[j]++, A[k]++;
        for(int x=100;x;x--) if(A[x] == 1) {
            if(x == i || x == j || x == k) f = 1;
            break;
        }
        A[i]--, A[j]--, A[k]--;
        cnt+=f;
    }
    cout << cnt;
    return 0;
}