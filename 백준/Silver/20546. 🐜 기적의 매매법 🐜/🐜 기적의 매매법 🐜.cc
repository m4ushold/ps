#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(14);
    for(int &i:v) cin >> i;
    int a=n, b=n, as=0, bs=0;
    for(int i=0;i<v.size();i++) {
        while(a>=v[i]) as++, a-=v[i];
        if(2<i) {
            if(v[i - 3] < v[i - 2] && v[i - 2] < v[i - 1]) {
                while(bs>0) bs--, b+=v[i];
            } else if(v[i - 3] > v[i - 2] && v[i - 2] > v[i - 1]) {
                while(b>=v[i]) bs++, b-=v[i];
            }
        }
    }
    int aa=a+as*v.back(), bb=b+bs*v.back();
    if(aa>bb) cout << "BNP";
    else if(aa<bb) cout << "TIMING";
    else cout << "SAMESAME";
}