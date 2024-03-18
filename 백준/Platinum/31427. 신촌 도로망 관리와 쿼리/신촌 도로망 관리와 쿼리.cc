#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, M, Q, P[50505], A[3030][5];
vector<tuple<ll,ll,char>> E;

void Init(int n) { for(int i=1;i<=n;i++) P[i]=i;}
int Find(int v) { return P[v]==v? v: P[v]=Find(P[v]); }
bool Union(int u, int v) { return Find(u)!=Find(v) && (P[P[u]]=P[v], true); }

int h(string s) {
    int res=0;
    for(int j=0,i=625;j<s.size();j++,i/=5) res+=(s[j]-'A')*i;
    return res;
}

void kruskal(string s)
{
    Init(N);
    vector<int> v(101);
    for(int i=0;i<5;i++) v[s[i]]=i;
    sort(E.begin(),E.end(), [&](auto a, auto b) {
        return v[get<2>(a)]<v[get<2>(b)];
    });
    int t=h(s);
    for(auto [u,v,z]:E) if(Union(u,v)) ++A[t][z-'A'];
}

int main(void)
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;
    for(int i=0,u,v;i<M;i++) {
        char z; cin >> u >> v >> z;
        E.emplace_back(u,v,z);
    }
    string s="ABCDE";
    do {
        kruskal(s);
    } while(next_permutation(s.begin(),s.end()));
    
    for(int i=0;i<Q;i++) {
        vector<ll> v(5);
        vector<pair<ll,char>> a(5);
        for(int j=0;j<5;j++) cin >> v[j], a[j]={v[j], j+'A'};
        sort(a.begin(),a.end());
        string tmp;
        for(auto [b,c]:a) tmp+=c;
        int t=h(tmp);

        ll res=0;
        for(int j=0;j<5;j++) res+=v[j]*A[t][j];
        cout << res << '\n';
    }
    return 0;
}