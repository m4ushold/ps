#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

int N, A[101010], P[101010], C[101010];
vector<int> B[101010];

void sol(int tc) {
    cin >> N >> A[1];
    B[1].push_back(A[1]);
    int ans=0;
    for(int i=2;i<=N;i++) {
        cin >> P[i] >> A[i];
        int j = i, x = A[i];
        while(j && C[j] == 0) {
            B[j].push_back(x);
            sort(all(B[j]));
            for(int k=0;k+2<B[j].size();k++) {
                if(B[j][k] + B[j][k+1] > B[j][k+2]) {
                    C[j] = 1;
                    ans++;
                    break;
                }
            }
            j = P[j];
        }
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}