#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll A[22]={1,1,2}, S[22];

void dnc(ll n, ll k) {
    if(n==0) return;

    ll sum=0;
    for(int j=0;j<n;j++) {
        sum += A[j] * A[n-j-1];
        if(sum > k) {
            k -= sum - A[j] * A[n-j-1];

            if(j) {
                cout << '(';
                dnc(j, k/A[n-j-1]);
                cout << ')';
            }

            cout << 'X';

            if(n-j-1) {
                cout << '(';
                dnc(n-j-1, k%A[n-j-1]);
                cout << ")";
            }
            return;
        }
    }
}

int sol() {
    int n=1, k; cin >> k;
    if(!k) return 0;
    k--;
    while(S[n]<=k) n++;

    dnc(n,k-(n?S[n-1]:0));
    cout << '\n';
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    S[1]=1, S[2]=3;
    for(int i=3;i<20;i++) {
        for(int j=0;j<i;j++) A[i]+=A[j]*A[i-j-1];
        S[i]=S[i-1]+A[i];
    }

    while(sol());
    return 0;
}