n,s = [input() for _ in range(2)]
print(min(s.count(i) for i in 'uospc'))