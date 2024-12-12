#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	ll n,w,l,h,ans[3]; cin >> n;
	for(int i=0;i<n;i++) {
		cin >> w >> l >> h;
		ans[0]=(l+h)*(l+h)+w*w;
		ans[1]=(w+h)*(w+h)+l*l;
		ans[2]=(l+w)*(l+w)+h*h;
		cout << *min_element(ans, ans+3) << '\n';
	}
    return 0;
}