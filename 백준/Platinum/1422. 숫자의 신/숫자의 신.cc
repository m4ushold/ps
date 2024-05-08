#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string arr[1001];
string arr2[1001];

bool Decending(string a, string b) {
	if (a.length() == b.length()) {
		return a > b;
	}
	return a.length() > b.length();
}

bool Decending2(string a, string b) {
	string A, B;

	A.append(a);
	A.append(b);
	B.append(b);
	B.append(a);

	return A > B;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k, n; cin >> k >> n;
    vector<string> v(k);
    for(auto &i:v) cin >> i;
    sort(v.begin(),v.end(),[](auto a, auto b){return a.size() == b.size() ? a>b : a.size() > b.size(); });
    for(int i=0;i<n-k;i++) v.push_back(v[0]);
    sort(v.begin(),v.end(),[](auto a, auto b){return a+b>b+a;});
    for(auto i:v) cout << i;
	return 0;
}