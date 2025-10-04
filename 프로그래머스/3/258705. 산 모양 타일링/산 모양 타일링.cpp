#include <string>
#include <vector>
#include <iostream>

using namespace std;
using ll=long long;

constexpr int mod = 10007;

int solution(int n, vector<int> tops) {
    int answer = 0;
    vector<ll> dp(2*n+2);
    dp[0]=1;
    for(int i=1;i<=2*n+1;i++) {
        if((~i&1) && tops[i/2-1]) dp[i]+=dp[i-1], dp[i]%=mod;
        dp[i]+=dp[i-1], dp[i]%=mod;
        if(i>1) dp[i]+=dp[i-2], dp[i]%=mod;
    }
    
    answer = dp.back();
    return answer;
}