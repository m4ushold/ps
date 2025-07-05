#include <bits/stdc++.h>
using namespace std;

int N, W, D[5050], P[5050], C[5050], T[5050][5050], M[5050][5050];
string S[5050];

bool chk(int r) {
    vector<int> p(N+1);
    D[0]=-1;
    for(int i=1;i<=N;i++) {
        D[i] = 1e9;
        for(int j=max(1, i-r+1);j<=i;j++) {
            if(D[i] > D[j-1] + M[j][i] + 1) {
                D[i] = D[j-1] + M[j][i] + 1;
                p[i] = j-1;
            }
        }
    }
    if(D[N] <= W) {
        for(int i=1;i<=N;i++) P[i]=p[i];
    }
    return D[N] <= W;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> W;
    for(int i=1;i<=N;i++) cin >> S[i], M[i][i] = S[i].size();
    for(int len=2;len<=N;len++) {
        for(int i=1;i+len-1<=N;i++) {
            int j=i+len-1;
            M[i][j] = max(M[i][j-1], M[j][j]);
        }
    }

    int l=1, r=N;
    while(l<r) {
        int m = l+r>>1;
        if(chk(m)) r=m;
        else l=m+1;
    }

    vector<int> v;
    v.push_back(N);
    while(P[v.back()]) v.push_back(P[v.back()]);
    reverse(v.begin(),v.end());

    int row = l, col = v.size();

    int p=1, rr=1;
    for(int i:v) {
        for(int j=p,tmp=1;j<=i;j++,tmp++) T[tmp][rr] = j, C[rr]=max(C[rr], M[j][j]);
        p=i+1;
        rr++;
    }

    cout << row << ' ' << col << '\n';
    for(int i=1;i<=col;i++) cout << C[i] << ' ';
    cout << '\n';
    for(int i=1;i<=row;i++) {
        for(int j=1;j<=col;j++) cout << S[T[i][j]] << string(C[j]-M[T[i][j]][T[i][j]]+1,' ');
        cout << '\n';
    }
    return 0;
}