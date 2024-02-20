#include <bits/stdc++.h>
using namespace std;
using ll=long long;

// bubble_sort(A[1..N]) { # A[1..N]을 오름차순 정렬한다.
//     for last <- N downto 2
//         for i <- 1 to last - 1
//             if (A[i] > A[i + 1]) then A[i] <-> A[i + 1]  # 원소 교환
// }
int N, K, C;

void f(vector<int> v) {
    for(int i=v.size()-1;i>0;i--) {
        for(int j=0;j<v.size()-1;j++) {
            if(v[j]>v[j+1]) swap(v[j], v[j+1]), ++C;
            if(C==K) {
                cout << min(v[j],v[j+1]) << " " << max(v[j],v[j+1]);
                return;
            }
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