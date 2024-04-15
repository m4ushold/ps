#include <bits/stdc++.h>
using namespace std;
using ll=long long;

char A[5][101];

void f(int i, char c) {
    A[0][i+2]=c;
    A[1][i+1]=A[1][i+3]=c;
    A[2][i]=A[2][i+4]=c;
    A[3][i+1]=A[3][i+3]=c;
    A[4][i+2]=c;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0;i<5;i++) for(int j=0;j<101;j++) A[i][j]='.';
    string s; cin >> s;
    for(int i=0;i<s.size();i++) {
        f(i*4,'#');
        A[2][i*4+2] = s[i];
    }
    for(int i=2;i<s.size();i+=3) f(i*4, '*');
    
    for(int i=0;i<5;i++) {
        for(int j=0;j<s.size()*4+1;j++) cout << A[i][j];
        cout << '\n';
    }
    return 0;
}