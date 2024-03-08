#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, B, A[101010], C[101010], L[404], S[404];
void init(int n) {
    N=n, B=sqrt(N), C[1]=N;
    for(int i=0;i<N;i++) A[i]=1, S[i/B]++;
}
void push(int b) {
    if(!L[b]) return;
    for(int i=0;i<B;i++) A[b*B+i]=L[b];
    L[b]=0;
}
void update(int l, int r, int x) {
    if(l%B) push(l/B);
    if(r%B!=B-1) push(r/B);
    while(l<=r && l%B!=0) C[A[l]]--, C[x]++, A[l]=x, l++;
    while(l<=r && r%B!=B-1) C[A[r]]--, C[x]++, A[r]=x, r--;
    if(l<=r) for(int b=l/B;b<=r/B;b++) {
        if(L[b]) C[L[b]]-=S[b], C[x]+=S[b];
        else for(int j=b*B;j<(b+1)*B;j++) C[A[j]]--, C[x]++, A[j]=x;
        L[b]=x;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,c,q; cin >> n >> c >> q;
    init(n);
    while(q--) {
        ll p,x,a,b; cin >> p >> x >> a >> b;
        a%=n, b%=n;
        ll s=C[p]%n, m1=(a+s*s)%n, m2=(a+(s+b)*(s+b)%n)%n;
        update(min(m1,m2),max(m1,m2),x);
    }
    cout << *max_element(C, C+101010);
    return 0;
}