#include <bits/stdc++.h>
using namespace std;

int mask = (1<<8)-1;

int left_rotate(int cog) { return mask & ((cog<<1)^((cog&(1<<7) ? 1 : 0))); }

int right_rotate(int cog) { return mask & ((cog>>1) | (cog&1 ? 1<<7 : 0)); }

int rotate(int cog, int dir) { return dir==1 ? right_rotate(cog) : left_rotate(cog); }

int f(int a, int b) {
    return ((a>>5)&1) ^ ((b>>1)&1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(4);
    for(int i=0;i<4;i++) {
        string s; cin >> s;
        v[i] = stoi(s, 0, 2);
    }

    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int a, d; cin >> a >> d;
        --a;
        int l=a,r=a;

        while(l && f(v[l-1],v[l])) l--;
        while(r<3 && f(v[r],v[r+1])) r++;
        for(int i=l;i<=r;i++) {
            int dir=abs(i-a)&1 ? (d==1?-1:1) : d;
            v[i] = rotate(v[i],dir);
        }
    }

    int dap=0;
    for(int i=0;i<4;i++) dap+= (v[i]&(1<<7)) ? (1<<i) : 0;
    cout << dap;

    return 0;
}