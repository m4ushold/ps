#include <bits/stdc++.h>
using namespace std;

int R, G[1010101][2];

void add(int v, int n=R) {
    if(v<n) {
        if(G[n][0]) add(v,G[n][0]);
        else G[n][0]=v;
    }
    else {
        if(G[n][1]) add(v,G[n][1]);
        else G[n][1]=v;
    }
}

void p(int n=R) {
    if(!n) return ;
    p(G[n][0]);
    p(G[n][1]);
    cout << n << '\n';
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> R;
    while(cin >> n) add(n);
    p();
    return 0;
}