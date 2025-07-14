#include <bits/stdc++.h>
using namespace std;

int C[10101], F[505050];

vector<string> split(string &s) {
    vector<string> res;
    string t;
    for(char c:s) {
        if(c == ',') res.push_back(t), t.clear();
        else t+=c;
    }
    res.push_back(t);
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<string,int> m, feat;
    for(int i=0;i<n;i++) {
        string s; cin >> s;
        m[s]=i;
    }
    C[0]=n;
    int r; cin >> r;
    int cnt=0;
    vector<array<string,3>> qq(r);
    vector<tuple<int,int,string>> qqq;
    for(auto &[a,st,f]:qq) {
        cin >> a;
        if(a == "U") {
            cin >> st >> f;
            for(auto j:split(f)) if(feat[j] == 0) feat[j]=++cnt;
        } else cin >> f;
        qqq.push_back({a=="U", m[st], f});
    }

    for(auto [op,st,f]:qqq) {
        int x=0;
        for(auto j:split(f)) {
            if(feat[j] == 0) {
                x=1024;
                break;
            }
            else x|=1<<(feat[j]-1);
        }
        if(op == 0) cout << C[x] << '\n';
        else if(x < 1024) {
            for(int j=0;j<=F[st];j++) if((j&F[st]) == j) C[j]--;
            F[st]=x;
            for(int j=0;j<=F[st];j++) if((j&F[st]) == j) C[j]++;
        }
    }
    return 0;
}