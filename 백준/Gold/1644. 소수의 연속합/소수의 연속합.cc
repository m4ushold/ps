#include <bits/stdc++.h>
using namespace std;

int N, s[4040404]={1,1}, cnt;

int main(void)
{
    for(int i=2;i*i<=4000000;i++) if(!s[i]) for(int j=2*i;j<=4000000;j+=i) s[j]=1;

    cin >> N;
    vector<int> v;
    for(int i=2;i<=N;i++) if(!s[i]) v.push_back(i);

    for (int i=0,j=0,sum=0;i<v.size()&&v[i]<=N;sum-=v[i++]) {
        while(sum < N && j<v.size()) sum+=v[j++];
        if (sum == N) cnt++;
    }
    cout << cnt << '\n';
    
    return 0;
}