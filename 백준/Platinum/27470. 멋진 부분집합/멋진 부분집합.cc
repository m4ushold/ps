#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1<<17;
int N, S[sz];
vector<int> P;

vector<int> factorize(int n) {
    vector<int> res;
    for(int i:P) if(n%i==0) {
        if(i*i>n) break;
        while(n%i==0) n/=i;
        res.push_back(i);
    }
    if(n>1) res.push_back(n);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    for(int i=2;i<sz;i++) if(!S[i]) {
        P.push_back(i);
        for(int j=2*i;j<sz;j+=i) S[j]=1;
    }
    cin >> N;
    vector<int> v(N);
    for(int &i:v) cin >> i;
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, N-1);

    for (int i = 0; i < 10; ++i) {
        int x = v[dist(gen)];
        auto fac = factorize(x);
        for(int f:fac) {
            vector<int> ans;
            for(int j:v) if(j%f == 0) {
                ans.push_back(j);
                if(ans.size() == (N+1)/2) {
                    cout << "YES\n";
                    for(int t:ans) cout << t << ' ';
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";    
    return 0;
}