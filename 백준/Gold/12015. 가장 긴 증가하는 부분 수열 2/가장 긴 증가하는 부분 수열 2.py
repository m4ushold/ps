import sys
input = sys.stdin.readline
n = input()
arr = list(map(int, input().split()))
dp = []
ans = 0
def bs_left(dp, target):
    left = 0
    right = len(dp) - 1
    while(left <= right):
        mid = (left + right) // 2
        if(dp[mid] < target):
            left = mid + 1
        else:
            right = mid - 1
    return left

for i in range(0,len(arr)):
    left = bs_left(dp, arr[i])
    if(left == len(dp)):
        dp.append(arr[i])
        ans += 1
    else:
        dp[left] = arr[i]
print(ans)