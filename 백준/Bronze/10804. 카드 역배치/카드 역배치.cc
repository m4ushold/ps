#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int A[22];

void rev(int s, int e) {
    while(s<e) swap(A[s++],A[e--]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    iota(A+1,A+21,1);
    for(int i=0,s,e;i<20;i++) cin >> s >> e, rev(s,e);
    for(int i=1;i<=20;i++) cout << A[i] << ' ';
    return 0;
}