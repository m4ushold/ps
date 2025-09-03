#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const ll INF = 1e15,MOD = 1e9 + 7;

ll N;
char arr[300][300];
set<string> m;
vector<string> s;

void check(int i){
    m.clear();
    for(int j = 0;j<N;j++) s[j].push_back(arr[i][j]);
    for(int j = 0;j<N;j++) m.insert(s[j]);
    if(m.size() >= i+1) return;
    for(int j = 0;j<N;j++) s[j].pop_back();
}

void rotate(int i){
    char tmp = arr[i][0];
    for(int j = 0;j<N-1;j++) arr[i][j] = arr[i][j+1];
    arr[i][N-1] = tmp;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> N;
    s.resize(N);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++) cin >> arr[i][j];
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            check(i);
            if(m.size() >= i+1) break;
            rotate(i);
        }
    }
    cout << "Yes\n";
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++) cout << arr[i][j];
        cout << "\n";
    }
}