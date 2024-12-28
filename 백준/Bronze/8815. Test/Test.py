for _ in range(int(input())):
    n = int(input())
    if n==1:
        print('A')
    else:
        print("BCBCDCDADABA"[(n-2)%12])