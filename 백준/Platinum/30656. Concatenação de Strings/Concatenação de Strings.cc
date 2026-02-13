#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

vector<int> GetFail(const string &p){
    int n = p.size();
    vector<int> fail(n);
    for(int i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}
vector<int> KMP(const string &s, const string &p){
    int n = s.size(), m = p.size();
    vector<int> fail = GetFail(p), ret;
    for(int i=0, j=0; i<s.size(); i++){
        while(j && s[i] != p[j]) j = fail[j-1];
            if(s[i] == p[j]){
            if(j + 1 == m) ret.push_back(i-m+1), j = fail[j];
            else j++;
        }
    }
    return ret;
}

void sol(string &s, string &p) {
    ll a = s.size(), b = p.size(), l = lcm<ll>(a,b);
    while(s.size() < p.size()) s+=s;
    auto v = KMP(s,p);
    int idx=0;
    while(idx<s.size()/2) {
        if(binary_search(all(v), idx) == false) {
            cout << "NAO" << endl;
            return;
        }
        idx+=p.size();
    }
    cout << l/a << ' ' << l/b << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s,p;
    while(cin >> s >> p && s!="#") sol(s,p);
    return 0;
}