#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 1010;
int N, A[sz], B[sz], AA[sz], BB[sz], CC[sz], U[sz];
vector<int> G[sz], R[sz];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
        G[i].push_back(A[i]);
        G[i].push_back(B[i]);
        R[A[i]].push_back(i);
        R[B[i]].push_back(i);
    }

    string ans(N, 'N');
    for(int i = 1; i <= N; i++){
        queue<int> q;

        memset(AA, 0, sizeof(AA));
        memset(U, 0, sizeof(U));
        q.push(i);
        U[i] = 1;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int x : R[v]){
                if(!U[x]){
                    U[x] = 1;
                    q.push(x);
                }
            }
        }
        for(int j = 1; j <= N; j++) AA[j] = U[j];

        memset(BB, 0, sizeof(BB));
        memset(U, 0, sizeof(U));
        q.push(A[i]);
        U[A[i]] = 1;
        U[i] = 1;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int x : R[v]){
                if(!U[x]){
                    U[x] = 1;
                    q.push(x);
                }
            }
        }
        for(int j = 1; j <= N; j++) BB[j] = U[j];

        memset(CC, 0, sizeof(CC));
        memset(U, 0, sizeof(U));
        q.push(B[i]);
        U[B[i]] = 1;
        U[i] = 1;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(int x : R[v]){
                if(!U[x]){
                    U[x] = 1;
                    q.push(x);
                }
            }
        }
        for(int j = 1; j <= N; j++) CC[j] = U[j];

        for(int s = 1; s <= N; s++){
            if(s == i) continue;
            if(AA[s] && BB[s] && CC[s]){
                ans[i-1] = 'Y';
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}