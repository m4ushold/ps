input()
s='(' + input().replace('(', '((').replace(')', '))').replace('+', ')+(') + ')'
print(len(s))
print(s)