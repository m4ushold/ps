#include <bits/stdc++.h>
using namespace std;

const int MAX_V=55;
int N, M, A[MAX_V], B[MAX_V], vi[MAX_V], G[MAX_V][MAX_V];

bool dfs(int v) 
{
    vi[v]=1;
    for(int i=0;i<N;i++) if(G[v][i]) {
        if(B[i]==-1 || !vi[B[i]] && dfs(B[i])) {
            A[v]=i, B[i]=v;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    vector<string> v(N);
    cin.ignore();
    for(int i=0;i<N;i++) {
        string s; getline(cin,s);
        set<char> st;
        for(char c:s) if(isupper(c) && !st.count(c)) v[i]+=c, st.insert(c);
    }
    
    while(M--) {
        string s; cin >> s;
        if(s.size()>N) {cout << "NO\n"; continue;}

        for(int i=0;i<MAX_V;i++) {
            A[i]=B[i]=-1;
            for(int j=0;j<MAX_V;j++) G[i][j]=0;
        }
        
        for(int i=0;i<N;i++) {
            for(int j=0;j<s.size();j++) {
                for(char k:v[i]) {
                    if(s[j]==k) {G[i][j]=1; break;}
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<N;i++) {
            memset(vi, 0, sizeof vi);
            cnt+=dfs(i);
        }

        cout << (cnt==s.size() ? "YES\n":"NO\n");
    }
    return 0;
}