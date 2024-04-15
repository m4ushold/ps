#include <bits/stdc++.h>
using namespace std;

bool chk(string s) {
    int v=0,c=0;
    for(char i:s) {
        if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u') v++;
        else c++;
    }
    return v>0 && c>1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<char> v(m), b(m);
    for(char &i:v) cin >> i;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) b[i]=1;
    do {
        string s;
        for(int i=0;i<m;i++) if(b[i]) s+=v[i];
        if(chk(s)) cout << s << '\n';
    } while(prev_permutation(b.begin(),b.end()));
    return 0;
}