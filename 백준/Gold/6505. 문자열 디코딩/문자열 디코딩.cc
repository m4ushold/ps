#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, K, B[101], A[101], R[101];
vector<int> V;

ll dfs(int i, int d=0) {
    if(B[i]) return d;
    B[i]=1;
    V.push_back(i);
    return dfs(A[i], d+1);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin >> N >> K && N) {
        for(int i=1;i<=N;i++) cin >> A[i];
        string s;
        cin.get(), getline(cin,s);
        K++;
        
        memset(B, 0, sizeof B);
        for(int i=1;i<=N;i++) if(!B[i]) {
            V.clear();
            int p=dfs(i), r=K%p;
            for(int j=0;j<p;j++) {
                R[V[j]]=A[V[(j-r+p)%p]];
            }
        }
        for(int i=1;i<=N;i++) cout << s[R[i]-1];
        cout << '\n';
    }
    return 0;
}