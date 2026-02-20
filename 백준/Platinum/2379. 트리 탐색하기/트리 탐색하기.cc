#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)),(v).end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

vector<int> G[3030], GG[3030];
int pv_a, pv_b; 

void at(string &a, int s, int e, int p=0) {
    int x = ++pv_a; 
    G[p].push_back(x);
    ++s, --e;
    int stk = 0, ss = s;
    for(int i=s;i<=e;i++) {
        if(a[i]=='1') stk++;
        else stk--;
        if(stk == 0) {
            at(a, ss, i, x);
            ss = i+1;
        }
    }
}

void bt(string &b, int s, int e, int p=0) {
    int x = ++pv_b;
    GG[p].push_back(x);
    ++s, --e;
    int stk = 0, ss = s;
    for(int i=s;i<=e;i++) {
        if(b[i]=='1') stk++;
        else stk--;
        if(stk == 0) {
            bt(b, ss, i, x);
            ss = i+1;
        }
    }
}

string aa(int v=1, int p=-1) {
    vector<string> vec;
    for(int i:G[v]) if(i!=p) {
        vec.push_back(aa(i,v));
    }
    sort(all(vec));
    string res="1";
    for(auto i:vec) res += i;
    res+="0";
    return res;
}

string bb(int v=1, int p=-1) {
    vector<string> vec;
    for(int i:GG[v]) if(i!=p) {
        vec.push_back(bb(i,v));
    }
    sort(all(vec));
    string res="1";
    for(auto i:vec) res += i;
    res+="0";
    return res;
}

void sol(int tc) {
    for(int i=0;i<3030;i++) G[i].clear(), GG[i].clear();
    pv_a = 0; pv_b = 0;
    
    string a,b; cin >> a >> b;
    
    a = "0" + a + "1";
    b = "0" + b + "1";
    
    at(a,0,a.size()-1); 
    bt(b,0,b.size()-1);
    
    cout << (aa() == bb()) << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}