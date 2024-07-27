#include <bits/stdc++.h>
using namespace std;

map<string,double> m({{"N", 0}, {"E", 90}, {"S", 180}, {"W", 270}, {"NE", 45}, {"SE", 135}, {"SW", 225}, {"NW", 315}});

double Get(string s) {
    if(s.size()<=2) return m[s];

    string t=s.substr(s.size()-2);
    double ret=m[t], deg=45.0/2;
    
    int dir;
    if(t=="NE") dir=1;
    else if(t=="SE") dir=2;
    else if(t=="SW") dir=3;
    else if(t=="NW") dir=4;

    for(int i=s.size()-3;i>=0;i--, deg/=2) {
        if(dir==1) {
            if(s[i]=='N') ret-=deg;
            else ret+=deg;
        }
        else if(dir==2) {
            if(s[i]=='E') ret-=deg;
            else ret+=deg;
        }
        else if(dir==3) {
            if(s[i]=='S') ret-=deg;
            else ret+=deg;
        }
        else if(dir==4) {
            if(s[i]=='W') ret-=deg;
            else ret+=deg;
        }
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    string a, b; cin >> a >> b;
    double aa=Get(a), bb=Get(b);
    cout << fixed << setprecision(12) << min(abs(bb-aa), 360-abs(bb-aa));
    return 0;
}