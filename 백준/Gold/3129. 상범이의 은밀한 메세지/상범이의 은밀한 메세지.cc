#include <bits/stdc++.h>
using namespace std;

string getKey(string ct, string pt) {
    string key;
    for(int i=0;i<pt.size();i++) key+=(ct[i]-pt[i]+26)%26+'a';
    return key;
}

bool isKey(string &key) {
    for(int len=1;len<=key.size()/2;len++) {
        int f=1;
        for(int i=0;i+len<key.size();i++) if(key[i]!=key[i+len]) {
            f=0;
            break;
        }
        if(f) {
            key=key.substr(0,len);
            return 1;
        }
    }
    return 0;
}

string decode(string ct, string key) {
    string pt;
    for(int i=0;i<ct.size();i++) {
        pt+=(ct[i]-key[i%key.size()]+26)%26+97;
    }
    return pt;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string ct, pt; cin >> ct >> pt;
    for(int i=0;i<=ct.size()-pt.size();i++) {
        string key = getKey(ct.substr(i, pt.size()), pt);
        if(isKey(key)) {
            int a = i%key.size();
            if(a) key = key.substr(key.size()-a) + key.substr(0, key.size()-a);
            cout << decode(ct, key);
            return 0;
        }
    }
    return 0;
}