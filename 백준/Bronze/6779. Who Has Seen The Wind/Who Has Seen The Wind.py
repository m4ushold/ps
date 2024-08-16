def f(h, m):
    for t in range(1, m + 1):
        a = -6 * t**4 + h * t**3 + 2 * t**2 + t
        if a <= 0:
            print(f"The balloon first touches ground at hour: {t}")
            return
    print("The balloon does not touch ground in the given time.")

h=int(input())
m=int(input())
f(h, m)