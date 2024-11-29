d1, d2, d3 = map(int, input().split())
a = (d1+d2-d3)/2
b,c = d1-a,d2-a

if min(a,b,c) > 0: print("1\n%.1f %.1f %.1f" %(a, b, c))
else: print(-1)