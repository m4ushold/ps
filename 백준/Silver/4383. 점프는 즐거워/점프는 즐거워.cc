#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin >> n) {
        vector<int> v(n), a;
        for(int &i:v) cin >> i;
        for(int i=1;i<n;i++) a.push_back(abs(v[i]-v[i-1]));
        sort(a.begin(),a.end());
        int f=1;
        for(int i=0;i<n-1;i++) if(a[i]!=i+1) {f=0; break;}
        cout << (f ? "Jolly\n" : "Not jolly\n");
    }
    return 0;
}