#include <bits/stdc++.h>
using namespace std;
using ll=long long;

// selection_sort(A[1..N]) { # A[1..N]을 오름차순 정렬한다.
//     for last <- N downto 2 {
//         A[1..last]중 가장 큰 수 A[i]를 찾는다
//         if (last != i) then A[last] <-> A[i]  # last와 i가 서로 다르면 A[last]와 A[i]를 교환
//     }
// }
int N, K, C;

void f(vector<int> v) {
    for(int i=v.size()-1;i>0;i--) {
        int mx=0, j=0;
        for(int k=0;k<=i;k++) if(mx<v[k]) mx=v[k], j=k;
        if(v[i]!=v[j]) swap(v[i], v[j]), ++C;
        if(C==K) {
            if(v[i]>v[j]) swap(v[i],v[j]);
            cout << v[i] << ' ' << v[j];
            return;
        }
    }
}



int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    vector<int> v(N);
    for(int &i:v) cin >> i;
    f(v);
    if(C<K) cout << -1;
    return 0;
}