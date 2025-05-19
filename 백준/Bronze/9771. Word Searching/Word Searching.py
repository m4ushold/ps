w = input()

ans=0
while True:
    try:
        s = input()
        ans += s.count(w)
    except:
        break

print(ans)