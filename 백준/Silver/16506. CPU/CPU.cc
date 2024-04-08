#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    map<string,int> m({
        {"ADD",0},
        {"SUB", 1},
        {"MOV", 2},
        {"AND", 3},
        {"OR", 4},
        {"NOT", 5},
        {"MULT", 6},
        {"LSFTL", 7},
        {"LSFTR", 8},
        {"ASFTR", 9},
        {"RL", 10},
        {"RR", 11},
    });
    int t; cin >> t;
    while(t--) {
        string op;
        int rd, ra, rb;
        cin >> op >> rd >> ra >> rb;
        int f=0;
        if(op.back()=='C') f=1, op.pop_back();
        cout << bitset<4>(m[op]) << f << 0;
        cout << bitset<3>(rd) << bitset<3>(ra);
        if(f) cout << bitset<4>(rb) << '\n';
        else cout << bitset<3>(rb) << "0\n";
    }
    return 0;
}