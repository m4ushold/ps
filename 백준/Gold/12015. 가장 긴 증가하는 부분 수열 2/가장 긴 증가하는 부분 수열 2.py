import sys
input = sys.stdin.readline
n = input()
arr = list(map(int, input().split()))
dp = []
ans = 0
for i in range(0,len(arr)):
    left = 0
    right = len(dp) - 1
    target = arr[i]
    while(left <= right):
        mid = (left + right) // 2
        if(dp[mid] < target):
            left = mid + 1
        else:
            right = mid - 1
    if(left == len(dp)):
        dp.append(target)
        ans += 1
    else:
        dp[left] = target
print(ans)