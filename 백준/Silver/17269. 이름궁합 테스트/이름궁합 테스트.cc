#include <bits/stdc++.h>
using namespace std;

int F[26] = {3, 2, 1, 2, 4, 3, 1, 3, 1, 1, 3, 1, 3, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; string a,b;
    cin >> n >> m >> a >> b;
    vector<int> v;
	for(int i=0; i<max(n,m); i++){
		if(n > i) v.push_back(F[a[i]-65]);
		if(m > i) v.push_back(F[b[i]-65]);
	}
	
    while(v.size()>2) {
        vector<int> t(v.size()-1);
        for(int i=1;i<v.size();i++) t[i-1]=(v[i-1]+v[i])%10;
        v=t;
    }
    cout << v[0]*10+v[1] << "%";
}