#include <bits/stdc++.h>
using namespace std;

const int MOD=9901;
int N, D[101010]={1,3};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
	for(int i=2;i<=N;i++) D[i]=(2*D[i-1]%MOD + D[i-2])%MOD;
	cout << D[N];
    return 0;
}