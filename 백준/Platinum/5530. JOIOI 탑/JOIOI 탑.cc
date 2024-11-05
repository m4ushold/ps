#include <bits/stdc++.h>
using namespace std;

int N;
string s;

bool chk(int m) {
    int res=0, tmp=m;
    vector<int> v(3);
    for(char c:s) {
        if(c=='I' && m) m--, v[1]++;
        else if(c=='O') {
            if(v[1]) v[1]--, v[2]++;
        } else if(c=='J') {
            if(v[2]) v[2]--, res++;
        } else if(c=='I') {
            if(v[2]) v[2]--, res++;
        }
    }
    return tmp==res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> s;
    int l=0, r=0;
    for(char c:s) if(c=='I') r++;
    reverse(s.begin(),s.end());
    while(l<r) {
        int m=l+r+1>>1;
        if(chk(m)) l=m;
        else r=m-1;
    }
    cout << l;
    return 0;
}