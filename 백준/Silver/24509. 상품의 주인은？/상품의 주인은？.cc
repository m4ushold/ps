#include <bits/stdc++.h>
using namespace std;

struct stu {
    int g, n;
    bool operator<(const stu& a) const {
        if(g== a.g) return n > a.n;
        return g < a.g;
    }
};

priority_queue<stu> PQ[4];
int F[202020];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for(int i=0;i<n;i++) {
        int t; cin >> t;
        for(int j=0,a;j<4;j++) {
            cin >> a;
            PQ[j].push({a,t});
        }
    }
    for(int i=0;i<4;i++) {
        while(F[PQ[i].top().n]) PQ[i].pop();
        int a=PQ[i].top().n;
        cout << a << ' ';
        F[a]=1;
    }
    return 0;
}