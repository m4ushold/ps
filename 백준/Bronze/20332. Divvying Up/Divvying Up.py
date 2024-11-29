input()
print(['no', 'yes'][sum(list(map(int, input().split())))%3==0])