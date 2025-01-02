#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    int mx=0;
    do {
        set<int> s;
        int cnt=0, sum=0;
        for(int i:v) {
            sum+=i;
            s.insert(sum);
            if(s.count(sum-50)) cnt++;
        }
        mx=max(mx,cnt);
    } while(next_permutation(v.begin(),v.end()));
    cout << mx;
    return 0;
}