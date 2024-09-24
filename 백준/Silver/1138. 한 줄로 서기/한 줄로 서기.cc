#include <bits/stdc++.h>
using namespace std;

int N, A[22];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,a;i<=N;i++) {
        cin >> a;
        int j=0;
        while(a>=0) {
            if(!A[j]) a--;
            j++;
        }
        while(A[j]) j++;
        A[j]=i;
    }
    for(int i=1;i<=N;i++) cout << A[i] << ' ';
    return 0;
}