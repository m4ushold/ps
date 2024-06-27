#include <bits/stdc++.h>
using namespace std;
 
char f(char a) {return a=='L' ? 'R' : 'L';}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin >> n >> k;
    string s; cin >> s;
    char p='L';
 
    int cnt=0;
    for(char c:s) {
        if(p!=c) cnt++, p=f(p);
        p=f(p);
    }
 
    cout << max(k-cnt, 0);
    
    return 0;
}