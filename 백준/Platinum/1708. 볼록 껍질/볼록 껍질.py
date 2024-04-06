from functools import cmp_to_key

def ccw(a, b, c):
    res = a[0]*b[1]+b[0]*c[1]+c[0]*a[1]
    res -= b[0]*a[1]+c[0]*b[1]+a[0]*c[1]
    return (res>0) - (res<0)

def distance(a, b):
    dx,dy=a[0]-b[0], a[1]-b[1]
    return dx*dx+dy*dy

def comp(p1, p2):
    dir = ccw([0, 0], p1, p2)
    if dir > 0:
        return -1
    if dir == 0:
        return 1 if distance([0,0],p1) > distance([0,0],p2) else -1
    if dir < 0:
        return 1
    
def convexHull(points:list):
    points = sorted(points, key=lambda x: (x[1], x[0]))
    mn = points[0]

    points = sorted([[x-mn[0], y-mn[1]] for x, y in points[1:]], key=cmp_to_key(comp))
    points = [mn] + [[x+mn[0], y+mn[1]] for x, y in points]

    stk=[]
    for point in points:
        while len(stk)>=2 and ccw(stk[-2], stk[-1], point)<=0:
            stk.pop()
        stk.append(point)
    return stk

n = int(input())
points = []
for _ in range(n):
    x, y = map(int, input().split())
    points.append([x, y])

hull = convexHull(points)
print(len(hull))