#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll F[55]={1,1};

void f(string &s, int n, int k) {
    if(n<=1 || k==1) return;

    if(k<=F[n-2]+1) {
        s+='L';
        f(s,n-2,k-1);
    } else {
        s+='R';
        f(s,n-1,k-F[n-2]-1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=2;i<55;i++) F[i]=F[i-1]+F[i-2]+1;

    int n,s,e; cin >> n >> s >> e;
    string a,b;
    f(a,n,s), f(b,n,e);
    int i=0;
    while(i<min(a.size(),b.size()) && a[i]==b[i]) i++;
    cout << string(a.size()-i, 'U');
    for(;i<b.size();i++) cout << b[i];
    return 0;
}