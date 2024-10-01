#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,h,w; cin >> n >> h >> w;
	vector<string> v(h);
	for(auto &i:v) cin >> i;
	for(int i=0;i<n;i++) {
		char c='?';
		for(int j=i*w;j<(i+1)*w;j++) for(int k=0;k<h;k++) {
			if(v[k][j]!='?') {
				c=v[k][j];
				break;
			}
		}
		cout << c;
	}
	return 0;
}