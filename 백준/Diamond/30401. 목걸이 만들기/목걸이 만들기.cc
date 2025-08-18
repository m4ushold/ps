#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int sz=1<<19;
int N, M, V[sz], A[sz], D[sz];
vector<ll> G[sz];

vector<ll> GetFail(const vector<ll> &p){
    ll n = p.size();
    vector<ll> fail(n);
    for(ll i=1, j=0; i<n; i++){
        while(j && p[i] != p[j]) j = fail[j-1];
        if(p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}
vector<ll> KMP(const vector<ll> &s, const vector<ll> &p){
    ll n = s.size(), m = p.size();
    vector<ll> fail = GetFail(p), ret;
    for(ll i=0, j=0; i<s.size(); i++){
        while(j && s[i] != p[j]) j = fail[j-1];
            if(s[i] == p[j]){
            if(j + 1 == m) ret.push_back(i-m+1), j = fail[j];
            else j++;
        }
    }
    return ret;
}

ll hash_tree(int v, int p=-1) {
    ll res=1;
    vector<ll> vec;
    for(ll i:G[v]) if(i!=p && !A[i]) vec.push_back(hash_tree(i,v));
    sort(vec.begin(),vec.end());
    for(ll i:vec) res<<=(64-__builtin_clzll(i)), res|=i;
    return res<<1;
}

vector<int> order_cycle(){
    for(int i=1;i<=N+M;i++) D[i]=G[i].size(), A[i]=1;
    queue<int> q;
    for(int i=1;i<=N+M;i++) if(D[i]==1) q.push(i), A[i]=0;
    
    while(q.size()) {
        int v=q.front(); q.pop();
        for(int i:G[v]) if(A[i]) {
            if(--D[i]==1) A[i]=0, q.push(i);
        }
    }

    int s=-1,v,p;
    for(int i=1;i<=N+M;i++) if(A[i]) {s=i; break;}
    vector<int> res;

    if(s==-1) return res;
    v=s,p=-1;
    do {
        res.push_back(v);
        for(int i:G[v]) if(A[i] && i!=p) {
            p=v,v=i;
            break;
        }
    } while(v!=s);
    return res;
}

vector<ll> necklace() {
    for(ll i=0;i<sz;i++) G[i].clear(), V[i]=0, D[i]=0, A[i]=0;

    for(int i=1,u,v;i<=N+M;i++) cin >> u >> v, G[u].push_back(v), G[v].push_back(u);

    vector<ll> res;
    for(int i:order_cycle()) res.push_back(hash_tree(i));
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    vector<ll> s=necklace(), t=necklace();
    s.insert(s.end(),s.begin(),s.end());
    vector<ll> r=s;
    reverse(r.begin(),r.end());
    int ans = KMP(s,t).size() + KMP(r,t).size();
    cout << (ans ? "Retry" : "Go to Minjun");
    return 0;
}