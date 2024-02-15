#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int T, A[202];

void rm(string s) { for(char c:s) --A[c]; }

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        string s; cin >> s;
        for(char c:s) ++A[c];
        s="";
        while(A['Z']) rm("ZERO"), s+='0';
        while(A['W']) rm("TWO"), s+='2';
        while(A['U']) rm("FOUR"), s+='4';
        while(A['X']) rm("SIX"), s+='6';
        while(A['G']) rm("EIGHT"), s+='8';
        while(A['O']) rm("ONE"), s+='1';
        while(A['T']) rm("THREE"), s+='3';
        while(A['F']) rm("FIVE"), s+='5';
        while(A['S']) rm("SEVEN"), s+='7';
        while(A['N']) rm("NINE"), s+='9';

        sort(s.begin(),s.end());
        cout << "Case #" << i << ": " << s << '\n';
    }
    return 0;
}