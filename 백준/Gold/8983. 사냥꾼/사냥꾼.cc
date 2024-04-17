#include <bits/stdc++.h>
using namespace std;
using Point=pair<int,int>;

int M, N, L;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N >> L;
    vector<int> v(M);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());

    int dap=0;
    for(int i=0,x,y;i<N;i++) {
        cin >> x >> y;
        auto it=upper_bound(v.begin(),v.end(), x);
        int f=0;
        if(it==v.begin()) f=y+abs(x-*it) <= L;
        else if(it==v.end()) f=y+abs(v.back()-x) <= L;
        else f = y+min(abs(x-*it), abs(x-*(it-1))) <= L;
        dap+=f;
    }
    cout << dap;

    return 0;
}