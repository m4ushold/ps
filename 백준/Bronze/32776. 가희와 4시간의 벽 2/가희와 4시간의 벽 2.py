a,b = int(input()), sum(list(map(int,input().split())))
if a<=b or a<=240:
    print('high speed rail')
else:
    print('flight')