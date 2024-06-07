#include <bits/stdc++.h>
using namespace std;

int N, M, D[101][101];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int tt=1;tt<=t;tt++) {
        double p; cin >> p;

        cin >> N;
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) {
            cin >> D[i][j];
            if(D[i][j]==-1) D[i][j]=1e9;
        }

        for(int k=1;k<=N;k++) {
            for(int i=1;i<=N;i++) {
                for(int j=1;j<=N;j++) D[i][j] = min(D[i][j], D[i][k]+D[k][j]);
            }
        }
        vector<int> v;
        for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) if(i!=j) v.push_back(D[i][j]);
        sort(v.begin(),v.end());
        
        cout << "Scenario #" << tt << ":\n" << v[ceil(p*v.size()/100)-1] << "\n\n";
    }

    return 0;
}