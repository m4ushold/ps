#include <bits/stdc++.h>
using namespace std;

int encrypt(char c) {
    if(c==' ') return 0;
    else if(isupper(c)) return c-'A'+1;
    return c-'a'+27;
}

int A[101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i, A[i]++;
    cin.ignore();
    string s; getline(cin, s);
    for(char c:s) A[encrypt(c)]--;
    for(int i=0;i<101;i++) if(A[i]) {
        cout << 'n';
        return 0;
    }
    cout << 'y';
    return 0;
}