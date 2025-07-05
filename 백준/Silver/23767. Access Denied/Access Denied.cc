#include <bits/stdc++.h>
using namespace std;

const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int qry(string s) {
    cout << s << endl;
    string res;
    getline(cin, res);

    if (res.find("ACCESS GRANTED") != string::npos) {
        exit(0);
    }

    int l = res.find('(');
    int r = res.find("ms");
    int t = stoi(res.substr(l + 1, r - l - 1));

    return t;
}

int main() {
    int len=20;
    for(int i=1;i<20;i++) {
        if(qry(string(i, 'a')) > 5) {
            len=i;
            break;
        }
    }

    string pw(len, 'a');
    for(int i=0;i<len;i++) {
        for(char c:chars) {
            pw[i]=c;
            int t = qry(pw), cnt = (t-5)/9;
            if(cnt > i+1) {
                break;
            } if(t == 0) {
                exit(0);
            }
        }
    }

    return 0;
}