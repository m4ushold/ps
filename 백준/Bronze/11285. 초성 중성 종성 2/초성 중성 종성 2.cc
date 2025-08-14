#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string aa,bb,cc; cin >> aa >> bb >> cc;
    vector<string> a = {"ㄱ","ㄲ","ㄴ","ㄷ","ㄸ","ㄹ","ㅁ","ㅂ","ㅃ","ㅅ","ㅆ","ㅇ","ㅈ","ㅉ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ"};
    vector<string> b = {"ㅏ","ㅐ","ㅑ","ㅒ","ㅓ","ㅔ","ㅕ","ㅖ","ㅗ","ㅘ","ㅙ","ㅚ","ㅛ","ㅜ","ㅝ","ㅞ","ㅟ","ㅠ","ㅡ","ㅢ","ㅣ"};
    vector<string> c = {"","ㄱ","ㄲ","ㄳ","ㄴ","ㄵ","ㄶ","ㄷ","ㄹ","ㄺ","ㄻ","ㄼ","ㄽ","ㄾ","ㄿ","ㅀ",
                               "ㅁ","ㅂ","ㅄ","ㅅ","ㅆ","ㅇ","ㅈ","ㅊ","ㅋ","ㅌ","ㅍ","ㅎ"};

    int ai,bi,ci=0;
    for(int i=0;i<a.size();i++) if(aa==a[i]) ai=i;
    for(int i=0;i<b.size();i++) if(bb==b[i]) bi=i;
    for(int i=0;i<c.size();i++) if(cc==c[i]) ci=i;
    int code = 0xAC00 + ((ai * b.size() + bi) * c.size() + ci);

    string s;
    s.push_back(char(0xE0 | ((code >> 12) & 0x0F)));
    s.push_back(char(0x80 | ((code >> 6) & 0x3F)));
    s.push_back(char(0x80 | (code & 0x3F)));
    cout << s << '\n';
    return 0;
}