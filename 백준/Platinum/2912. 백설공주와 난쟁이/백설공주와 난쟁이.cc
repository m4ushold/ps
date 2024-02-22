#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int N, Q, A[303030];
vector<int> B[10101];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    random_device rd;
    mt19937 g(rd());
    for(int i=1;i<=N;i++) cin >> A[i], B[A[i]].push_back(i);
    cin >> Q;
    while(Q--) {
        int l, r, res=0; cin >> l >> r;
        uniform_int_distribution<> rnd(l,r);
        for(int i=0,j,cnt;i<50;i++) {
            j=rnd(g);
            cnt=upper_bound(B[A[j]].begin(), B[A[j]].end(), r)-lower_bound(B[A[j]].begin(), B[A[j]].end(), l);
            if(cnt > (r-l+1)/2) {res=A[j]; break;}
        }
        if(res) cout << "yes " << res << '\n';
        else cout << "no\n";
    }

    return 0;
}