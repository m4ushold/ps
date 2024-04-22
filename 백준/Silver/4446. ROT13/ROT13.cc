#include <bits/stdc++.h>
using namespace std;

char F[202];

char f(char a) {
    if(islower(a)) return F[a];
    else if(isupper(a)) return toupper(F[tolower(a)]);
    else return a;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string v="aiyeou", c="bkxznhdcwgpvjqtsrlmf";
    for(int i=0;i<v.size();i++) F[v[i]]=v[(i+3)%v.size()];
    for(int i=0;i<c.size();i++) F[c[i]]=c[(i+10)%c.size()];
    string s; 
    while(getline(cin, s)) {
        for(char &c:s) c=f(c);
        cout << s << '\n';
    }
    
    return 0;
}