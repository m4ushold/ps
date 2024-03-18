#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> v(9);
    int a,b,s=0;
    for(int &i:v) cin >> i, s+=i;
    for(int i=0;i<9;i++) {
        int f=0;
        for(int j=i+1;j<9;j++) {
            if(s-v[i]-v[j]==100) {
                f=1;
                a=i, b=j;
                break;
            }
        }
        if(f) break;
    }
    for(int i=0;i<9;i++) if(i!=a && i!=b) cout << v[i] << '\n';
    return 0;
}