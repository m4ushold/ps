#include <bits/stdc++.h>

//#define endl '\n'
#define int long long
#define ll __int128_t
#define all(v) v.begin(),v.end()
using namespace std;

const vector<string> bits =
        {"00000000000001111111111111",
         "00000011111110000001111111",
         "00011100011110001110001111",
         "01101101100110110110110011",
         "10110110101011011011010101"};

map<string, char> s_to_c;

auto main() -> signed {
    for (int i = 0; i < 26; i++) {
        string cur;
        for (int j = 0; j < 5; j++) {
            cur.push_back(bits[j][i]);
        }
        s_to_c[cur] = (char) ('a' + i);
    }

    vector<vector<bool>> on(5, vector<bool>(10101));
    int length = 0;
    for (int i = 0; i < 5; i++) {
        string cur;
        for (int j = 0; j < 26; j++) {
            if (bits[i][j] == '1') {
                cur.push_back((char) ('a' + j));
            }
        }
        cout << "? " << cur << endl;

        int n;
        cin >> n;

        while (n--) {
            int x;
            cin >> x;
            on[i][x] = true;
            length = max(length, x);
        }
    }

    string res;
    for (int i = 1; i <= length; i++) {
        string cur;
        for (int j = 0; j < 5; j++) {
            cur.push_back((char) (on[j][i] + '0'));
        }
        res.push_back(s_to_c[cur]);
    }
    cout << "! " << res << endl;
    cin >> res;
    return 0;
}