n=int(input())
a=input()
b=input()
print(sum([1 if a[i]!=b[i] else 0 for i in range(n)]))