#include <bits/stdc++.h>
using namespace std;

int N;
char A[64][64];

string recur(int n, int i, int j)
{
    string s, tmp;
    if (n == 1) return to_string(A[i][j]-'0');

    tmp = recur(n/2, i, j) + recur(n/2, i, j+n/2) + recur(n/2, i+n/2, j) + recur(n/2, i+n/2, j+n/2);
    if (tmp == "0000") s="0";
    else if (tmp == "1111") s="1";
    else s+= "("+tmp+")";
    
    return s;
}

int main(void)
{
    cin >> N;
    for(int i=0,j;i<N;i++) for(j=0;j<N;j++) cin >> A[i][j];
    cout << recur(N, 0, 0) << '\n';
    return 0;
}
