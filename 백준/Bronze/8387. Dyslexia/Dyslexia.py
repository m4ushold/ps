a,b,c = [input() for i in range(3)]
print(sum([1 if i==j else 0 for i,j in zip(b,c)]))