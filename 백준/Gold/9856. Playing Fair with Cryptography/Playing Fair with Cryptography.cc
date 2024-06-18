#include <bits/stdc++.h>
using namespace std;

map<char,pair<int,int>> m;
vector<char> v;
int C[202];

char nxt(char c) {
    if(c=='Z') return 'A';
    else if(c=='I') return 'K';
    else return c+1;
}

string enc(string pt) {
    string ct="";
    auto [a,b]=m[pt[0]];
    auto [c,d]=m[pt[1]];
    if(a==c) {
        ct+=v[a*5+(b+1)%5];
        ct+=v[c*5+(d+1)%5];
    } else if(b==d) {
        ct+=v[(a+1)%5*5+b];
        ct+=v[(c+1)%5*5+d];
    } else {
        ct+=v[a*5+d];
        ct+=v[c*5+b];
    }
    return ct;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    cin.ignore();
    for(int i=1;i<=t;i++) {
        memset(C, 0, sizeof C);
        v.clear(), m.clear();

        cout << "Case " << i << ": ";
        string a,b,key,s; getline(cin, a), getline(cin, b);
        for(char c:a) if(isalpha(c)) key+=toupper(c);
        for(char c:b) if(isalpha(c)) s+=toupper(c);
        
        for(char c:key) if(!C[c]) C[c]=1, v.push_back(c);
        for(int i='A';i<='Z';i++) {
            if(i=='J') continue;
            if(!C[i]) v.push_back(i);
        }
        for(int i=0;i<25;i++) m[v[i]]={i/5,i%5};
        
        vector<string> vec;
        char ins='A';
        for(int i=0;i<s.size();i++) {
            if(i==s.size()-1 || s[i]==s[i+1]) {
                if(s[i]==ins) ins=nxt(ins);
                vec.push_back(s.substr(i,1)+ins), ins=nxt(ins);
            }
            else vec.push_back(s.substr(i,2)), i++;
        }

        transform(vec.begin(),vec.end(),vec.begin(),[](string s){return enc(s);});
        for(auto j:vec) cout << j;
        cout << '\n';
    }
    return 0;
}