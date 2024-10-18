#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int>& a) {
    vector<int> b(a.size());
    for(int i=0;i<a.size();i++) {
        for(int j=i+1;j<a.size();j++) if(a[j]>a[i]) b[i]++;
    }
    return b;
}

bool chk(vector<int>& a, vector<int>& b) {
    for(int i=0;i<a.size();i++) if(a[i]!=b[i]) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int &i:a) cin >> i;

    int cnt=0;
    while(1) {
        auto b = f(a);
        if(chk(a, b)) break;
        a=b, cnt++;
    }
    cout << cnt+1;
    return 0;
}