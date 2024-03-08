#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N=52, M, K, D[55][55];

int f(char c) { return (c<'a' ? c-'A' : c-'a'+26)+1; }
char g(int i) { return --i<26 ? i+'A' : i+'a'-26; }

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> M;
    cin.ignore();
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) D[i][j]=1e9;
    for(int i=1;i<=N;i++) D[i][i]=0;
    for(int i=1;i<=M;i++) {
        string s; getline(cin, s);
        int a=f(s[0]), b=f(s.back());
        D[a][b]=1;
    }

    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
        }
    }
    int cnt=0;
    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(i!=j && D[i][j]!=(int)1e9) ++cnt;
    cout << cnt << '\n';

    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(i!=j && D[i][j]!=(int)1e9) {
        cout << g(i) << " => " << g(j) << '\n';
    }
    

    return 0;
}