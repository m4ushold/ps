#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M, A[11];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    pair<int,int> h({0,0}), v({0,0});
    for(int i=1;i<=6;i++) {
        cin >> M >> A[i];
        if(M<=2 && A[i]>h.first) h={A[i], i};
        if(M>2 && A[i]>v.first) v={A[i],i};
    }
    A[0]=A[6], A[7]=A[1];
    cout << (h.first*v.first-abs(A[h.second-1]-A[h.second+1])*abs(A[v.second-1]-A[v.second+1]))*N;
    return 0;
}