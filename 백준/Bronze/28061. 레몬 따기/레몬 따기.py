n = int(input())
a = list(map(int,input().split()))
print(max([a[i]-n+i for i in range(len(a))]))