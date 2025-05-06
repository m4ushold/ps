#include <bits/stdc++.h>
using namespace std;

int N, A[11][11];
vector<tuple<int,int,int>> V;

bool chk() {
    for(int i=1;i<=9;i++) for(int j=i+1;j<=9;j++) if(A[i][j] == 0) return 0;
    return 1;
}

void f() {
    if(chk()) {
        cout << V.size() << '\n';
        for(auto [a,b,c]:V) cout << a << ' ' << b << ' ' << c << '\n';
        exit(0);
    }

    for(int i=1;i<=9;i++) for(int j=i+1;j<=9;j++) if(!A[i][j]) {
        for(int k=j+1;k<=9;k++) if(!A[i][k] && !A[j][k]) {
            V.push_back({i,j,k});
            A[i][j]=A[i][k]=A[j][k]=1;
            f();
            V.pop_back();
            A[i][j]=A[i][k]=A[j][k]=0;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1,a,b,c;i<=N;i++) {
        cin >> a >> b >> c;
        A[min(a,b)][max(a,b)]++;
        A[min(b,c)][max(b,c)]++;
        A[min(a,c)][max(a,c)]++;
    }
    for(int i=1;i<=9;i++) for(int j=i+1;j<=9;j++) if(A[i][j] > 1) return cout << "-1\n", 0;

    f();
    cout << "-1\n";
    return 0;
}