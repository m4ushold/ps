#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct Trie {
    map<char,Trie*> nxt;
    vector<int> out;
    Trie* fail;
    int term, id;
    Trie() : term(-1), id(0) {}
    void insert(const char *s, int id=1) {
        if(*s==0) {term=id; return ;}
        if(!nxt[*s]) nxt[*s]=new Trie();
        nxt[*s]->insert(s+1,id);
    }
    ~Trie() { 
        for(auto [c,t]:nxt) delete t;
        nxt.clear();
    }
} *root;

constexpr int MOD=998244353;

struct Mat {
    int n;
    vector<vector<ll>> m;
    Mat() {}
    Mat(int n, int f=0) : n(n) {set(n, f);}
    Mat(vector<vector<ll>> m) : m(m), n(m.size()) {}
    void set(int num, int f) {
        n=num;
        m = vector(n, vector<ll>(n, 0)); 
        if(f) for(int i=0;i<n;i++) m[i][i]=1;
    }
    vector<ll>& operator[](int i) {return m[i];}

    Mat operator*(Mat& mm) {
        Mat res(n);
        for(int i=0; i<n; i++){
			for(int j=0; j<n; j++) {
				for(int k=0; k<n; k++) {
                    res[i][j] = (res[i][j] + m[i][k] * mm[k][j] % MOD) % MOD;
                }
			}
		}
		return res;
    }
} MAT;

Mat pw(Mat m, ll n) {
    Mat res(m.n, 1);
    while(n) {
        if(n&1) res=res*m;
        m=m*m, n/=2;
    }
    return res;
}
ll pw(ll a, ll n) {
    ll res=1;
    while(n) {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD, n/=2;
    }
    return res;
}

void build(Trie *root) {
    queue<Trie*> q;
    root->fail=root, q.push(root);
    while(!q.empty()) {
        auto v=q.front(); q.pop();
        for(auto &[c,nxt]:v->nxt) {
            Trie *u=nxt;
            if(!u) continue;
            if(v==root) u->fail=root;
            else {
                Trie *t=v->fail;
                while(t!=root && !t->nxt[c]) t=t->fail;
                if(t->nxt[c]) t=t->nxt[c];
                u->fail=t;
            }
            u->out=u->fail->out;
            if(u->term!=-1) u->out.push_back(u->term);
            q.push(u);
        }
    }
}

int getSize(Trie *v) {
    static int pv=0;
    int res=1;
    v->id=pv++;
    if(v->term!=-1) {
        for(auto [c,i]:v->nxt) if(i) delete i;
        v->nxt.clear();
        return res;
    }
    for(auto [c,i]:v->nxt) if(i) res+=getSize(i);
    return res;
}

void dfs(Trie *u) {
    if(u->term!=-1) {
        MAT[u->id][MAT.n-1] = 1;
        return;
    }

    for(char c='a';c<='z';c++) {
        auto v = u;
        while(v!=root && !v->nxt[c]) v=v->fail;
        if(v->nxt[c]) v=v->nxt[c];
        
        MAT[u->id][v->id]++;
    }

    for(auto [c,i]:u->nxt) if(i) dfs(i);
}

bool find(const string &s, Trie *root) {
    auto v=root;
    for(char c:s) {
        while(v!=root && !v->nxt[c]) v=v->fail;
        if(v->nxt[c]) v=v->nxt[c];
        if(v->out.size()) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin >> m >> n;
    root=new Trie;
    vector<string> v(m);
    for(auto &i:v) cin >> i;
    sort(v.begin(),v.end(),[](string a, string b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    });
    for(auto s:v) {
        if(!find(s, root)) {
            root->insert(s.c_str());
            build(root);
        }
    }
    build(root);

    int sz = getSize(root);
    MAT.set(sz+1, 0);
    build(root);

    dfs(root);
    MAT[sz][sz]=26;
    auto mat = pw(MAT, n+1);

    for(auto i:MAT.m) {
        int sum=accumulate(i.begin(),i.end(),0);
        if(sum==1 || sum==26) ;
    }

    cout << (pw(26,n) - mat[0].back() + MOD) % MOD;
    return 0;
}