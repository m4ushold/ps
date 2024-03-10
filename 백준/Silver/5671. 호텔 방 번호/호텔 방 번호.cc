#include <bits/stdc++.h>
using namespace std;

int N, M, A[5050];

bool chk(string s) {
    vector<int> v(101);
    for(char c:s) {
        v[c]++;
        if(v[c]>1) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=1;i<=5000;i++) A[i]=A[i-1]+chk(to_string(i));
    while(cin >> N >> M) cout << A[M]-A[N-1] << '\n';
    return 0;
}