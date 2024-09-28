#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, A[101], D[101][10101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ll sum=0;
    for(int i=1;i<=N;i++) cin >> A[i], sum+=A[i];
    D[0][0]=-1;
    for(int i=1;i<=N;i++) {
        for(int j=0;j<=sum;j++) {
            D[i][j]=D[i-1][j];
            if(!D[i][j] && j-A[i]>=0 && D[i-1][j-A[i]]) D[i][j]=i;
        }
    }
    if((sum&1) || !D[N][sum/2]) return cout << -1, 0;

    vector<int> a,b;
    int n=sum/2, i=N;
    while(n>0) {
        a.push_back(D[i][n]);
        n-=A[D[i][n]];
        i--;
    }

    sort(a.begin(),a.end());
    int j=0;
    for(int i=1;i<=N;i++) {
        if(!binary_search(a.begin(),a.end(),i)) b.push_back(i);
    }
    for(int &i:a) i=A[i];
    for(int &i:b) i=A[i];

    int an=0,bn=0,ai=0,bi=0;
    vector<int> res;
    for(int i=0;i<N;i++) {
        if(an<=bn) an+=a[ai], ai++, res.push_back(a[ai-1]);
        else bn+=b[bi], bi++, res.push_back(b[bi-1]);
    }
    while(ai<a.size()) res.push_back(a[ai++]);
    while(bi<b.size()) res.push_back(b[bi++]);
    for(int i:res) cout << i << ' ';
    return 0;
}