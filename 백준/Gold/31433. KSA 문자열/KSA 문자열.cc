#include <bits/stdc++.h>
using namespace std;

char NXT[202];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    NXT['K']='S', NXT['S']='A', NXT['A']='K';
    string s; cin >> s;
    int ans=1e9, tmp=0, n=s.size();
    
    char t='K';
    for(char c:s) if(c==t) tmp++, t=NXT[t];
    tmp=n-tmp;
    ans=min(ans,tmp*2);

    t='S', tmp=0;
    for(char c:s) if(c==t) tmp++, t=NXT[t];
    tmp=n-tmp;
    ans=min(ans,tmp*2+2);
    
    t='A', tmp=0;
    for(char c:s) if(c==t) tmp++, t=NXT[t];
    tmp=n-tmp;
    ans=min(ans,tmp*2+4);

    cout << ans;
    return 0;
}