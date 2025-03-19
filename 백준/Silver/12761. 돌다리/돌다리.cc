#include <bits/stdc++.h>
using namespace std;

int A[101010];

bool chk(int x) {return 1<=x && x<=100'000;}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int a,b,n,m; cin >> a >> b >> n >> m;
    queue<int> q;
    q.push(n);
    A[n]=1;
    while(1) {
        int x=q.front(); q.pop();
        if(x == m) break;
        for(auto j:{1,a,b}) {
            if(chk(x-j) && !A[x-j]) q.push(x-j), A[x-j]=A[x]+1;
            if(chk(x+j) && !A[x+j]) q.push(x+j), A[x+j]=A[x]+1;
            if(chk(x*j) && !A[x*j]) q.push(x*j), A[x*j]=A[x]+1;
        }
    }
    cout << A[m]-1;
    return 0;
}