def score(events):
    sc = 0
    sc += int(9.23076 * (26.7 - events[0]) ** 1.835)
    sc += int(1.84523 * (events[1] - 75) ** 1.348)
    sc += int(56.0211 * (events[2] - 1.5) ** 1.05)
    sc += int(4.99087 * (42.5 - events[3]) ** 1.81)
    sc += int(0.188807 * (events[4] - 210) ** 1.41)
    sc += int(15.9803 * (events[5] - 3.8) ** 1.04)
    sc += int(0.11193 * (254 - events[6]) ** 1.88)
    return sc

for _ in range(int(input())):
    events = list(map(int, input().split()))
    print(score(events))