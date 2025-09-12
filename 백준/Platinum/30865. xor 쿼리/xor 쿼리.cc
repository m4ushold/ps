#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie *nxt[2];
    int sum=0;
    Trie() { nxt[0]=nxt[1]=0,sum=0; }
    void add(const char *s, int x) {
        sum+=x;
        if(*s==0) return ;
        if(!nxt[*s-'0']) nxt[*s-'0'] = new Trie();
        nxt[*s-'0']->add(s+1, x);
    }
    int kth(const char *s, int k, int res=0) {
        if(*s==0) return res;

        int a=(*s-'0');
        if(!nxt[0] || nxt[0]->sum == 0) return nxt[1]->kth(s+1, k, res<<1|(a^1));
        else if(!nxt[1] || nxt[1]->sum == 0) return nxt[0]->kth(s+1, k, res<<1|a);

        if(k <= nxt[a^1]->sum) return nxt[a^1]->kth(s+1,k,res<<1|1);
        return nxt[a]->kth(s+1,k-nxt[a^1]->sum,res<<1);
    }
    ~Trie() { for(int i:{0,1}) delete nxt[i]; }
} trie;

int N, Q, A[101010];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        trie.add(bitset<31>(A[i]).to_string().c_str(), 1);
    }
    cin >> Q;
    while(Q--) {
        int op,i,x; cin >> op >> i >> x;
        if(op==1) {
            trie.add(bitset<31>(A[i]).to_string().c_str(), -1);
            A[i]=x;
            trie.add(bitset<31>(A[i]).to_string().c_str(), 1);
        } else {
            cout << trie.kth(bitset<31>(x).to_string().c_str(),i) << '\n';
        }
    }
    return 0;
}