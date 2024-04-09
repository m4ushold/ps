n,r,b=int(input()),0,1

while n:
    if n&1:
        r+=b
    b*=3
    n>>=1

print(r)