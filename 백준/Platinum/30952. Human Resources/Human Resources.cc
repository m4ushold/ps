#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define prs(v) sort(all(v)), v.erase(unique(all(v)),v.end())
#define endl '\n'
using namespace std;
using ll=long long;
using pll=pair<ll,ll>;

map<string,int> in, ord;
map<string,vector<string>> G;

string dfs(string v) {
    static int pv=0;
    ord[v]=++pv;
    string res="1";
    for(auto i:G[v]) {
        res+=dfs(i);
    }
    return res+"0";
}

void encode() {
    cin.ignore();
    string s;
    while(getline(cin, s)) {
        string t, a;
        for(int i=0;i<s.size();i++) {
            if(s[i] == ':') {
                a = t;
                t.clear();
                i++;
            } else if(s[i] == ' ') {
                in[t]++;
                G[a].push_back(t);
                t.clear();
            } else t+=s[i];
        }
        G[a].push_back(t);
        in[t]++;
    }
    string root;
    for(auto i:G) {
        if(in[i.first] == 0) {
            root = i.first;
            break;
        }
    }
    string bin = dfs(root);
    vector<pair<int,string>> v;
    for(auto [s,i]:ord) v.push_back({i,s});
    sort(all(v));
    for(auto [i,s]:v) cout << s << endl;
    cout << bin << endl;
}

int P[606];
string S[606];
vector<int> GG[606];

void ddfs(string bin, int p=-1) {
    static int pv=0;
    P[pv] = p;
    int ord = pv;
    pv++;

    bin = bin.substr(1,bin.size()-2);
    string t;
    int sum=0;
    for(char c:bin) {
        t+=c;
        if(c == '1') sum+=1;
        else sum-=1;
        if(sum == 0) {
            ddfs(t, ord);
            t.clear();
        }
    }
}

void decode() {
    int idx=0;
    while(cin >> S[idx]) idx++;
    int n = --idx;
    string bin = S[idx];
    ddfs(bin);

    for(int i=1;i<n;i++) GG[P[i]].push_back(i);
    for(int i=0;i<n;i++) {
        if(GG[i].size()) {
            cout << S[i] << ": ";
            int t = GG[i].back();
            GG[i].pop_back();
            for(int j:GG[i]) cout << S[j] << ' ';
            cout << S[t] << endl;
        }
    }
}

void sol(int tc) {
    string s; cin >> s;
    if(s=="ENCODE") encode();
    else decode();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t=1;
    // cin >> t;
    for(int i=1;i<=t;i++) sol(i);
    return 0;
}