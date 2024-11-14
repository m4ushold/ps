f=''
for _ in range(2*int(input())-1):
    f+=input()
print(eval(f.replace('/', '//')))