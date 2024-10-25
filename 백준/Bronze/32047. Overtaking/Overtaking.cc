#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n && n) {
        vector<int> a(n), b(n);
        for(int &i:a) cin >> i;
        for(int &i:b) cin >> i;
        int f=0, cnt=0, aa=0, bb=0;
        for(int i=0;i<n;i++) {
            aa+=a[i], bb+=b[i];
            if(aa>bb) {
                if(f==-1) cnt++;
                f=1;
            } else if(aa<bb) {
                if(f==1) cnt++;
                f=-1;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}