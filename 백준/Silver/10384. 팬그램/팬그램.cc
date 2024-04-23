#include <bits/stdc++.h>
using namespace std;

int C[202];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    cin.ignore();
    for(int j=1;j<=t;j++) {
        memset(C, 0, sizeof C);
        string s; getline(cin,s);
        for(char c:s) if(isalpha(c)) C[tolower(c)]++;
        int mn=1e9;
        for(int i='a';i<='z';i++) mn=min(mn,C[i]);
        cout << "Case " << j << ": ";
        if(!mn) cout << "Not a pangram\n";
        else if(mn==1) cout << "Pangram!\n";
        else if(mn==2) cout << "Double pangram!!\n";
        else cout << "Triple pangram!!!\n";
    }
    
    return 0;
}