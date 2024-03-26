#include <bits/stdc++.h>
using namespace std;

int N, A[5050];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];

    vector<tuple<int,int,int>> v;
    for(int i=1;i<=N;i++) if(i!=A[i]) {
        int p=A[i], tmp=p;
        while(p!=i) {
            int t=A[p];
            v.push_back({p,1,N});
            A[p]=p;
            p=t;
        }
        v.push_back({i,1,N});
        v.push_back({tmp,1,N});
    }
    cout << v.size() << '\n';
    for(auto [a,b,c]:v) cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
}