#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a,b;
    if(n%3==2) {
        a.push_back(1), b.push_back(2);
        for(int i=3;i<n;i+=3) a.push_back(i), a.push_back(i+1), b.push_back(i+2);
    } else {
        for(int i=1;i<n;i+=3) a.push_back(i), a.push_back(i+1), b.push_back(i+2);
    }
 
    cout << a.size() << '\n';
    for(int i:a) cout << i << ' ';
    cout << "\n" << b.size() << '\n';
    for(int i:b) cout << i << ' ';
    return 0;
}