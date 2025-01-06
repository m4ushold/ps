#include <bits/stdc++.h>
using namespace std;

int mex(set<int> &s) {
    int res=0;
    while(s.count(res)) res++;
    return res;
}

int N, D[2020]={0,1,1,1};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=4;i<=2000;i++) {
        set<int> s;
        for(int x=1;x<=i-2;x++) {
            s.insert(D[max(0,x-3)] ^ D[i-x-2]);
        }
        D[i]=mex(s);
    }
    cout << (D[N]?1:2);
    return 0;
}