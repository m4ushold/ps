#include <bits/stdc++.h>
using namespace std;

int N, A[1010];

int getmn(int mn) {
    for(int i=mn;i<1010;i++) if(A[i]) return i;
    return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1,a;i<=N;i++) cin >> a, A[a]++;

    int p=-2;
    while(1) {
        int mn=getmn(0), mn2=getmn(mn+2);
        if(mn<0) break;

        if(A[mn+1] && mn2<0) {
            for(int j=0;j<A[mn+1];j++) cout << mn+1 << ' ';
            for(int j=0;j<A[mn];j++) cout << mn << ' ';
            A[mn]=A[mn+1]=0, p=mn;
        } else if(p+1 != mn) cout << mn << ' ', A[mn]--, p=mn;
        else if(A[mn+1]) cout << mn+1 << ' ', A[mn+1]--, p=mn+1;
        else cout << mn2 << ' ', A[mn2]--, p=mn2;
    }
    return 0;
}