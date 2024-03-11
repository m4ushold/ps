#include <bits/stdc++.h>
using namespace std;

int N, A[10000000];

int main()
{
    
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0,a;i<N;i++) {
        cin >> a;
        if(A[a]) {
            cout << a;
            break;
        }
        else A[a]++;
    }
    
    return 0;
}