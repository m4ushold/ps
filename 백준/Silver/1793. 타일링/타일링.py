import sys
input=sys.stdin.readline

while True:
    try:
        n = int(input().rstrip())
        dp = [1,1,3]+([0]*(300))

        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + 2 * dp[i - 2]

        print(dp[n])
    except:
        break