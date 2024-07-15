#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p=INT_MIN;
    while(cin >> n) {
        if(n<p) {cout << "Bad"; return 0;}
        p=n;
    }
    cout << "Good";
    return 0;
}