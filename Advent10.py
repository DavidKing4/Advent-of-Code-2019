from math import gcd
from math import atan as arctan
from math import pi
from sys import stdin


def cusAtan(x,y):
    if x == 0 and y < 0:
        return 0
    elif x > 0 and y < 0:
        return abs(arctan(x/y))
    elif x > 0 and y == 0:
        return pi/2
    elif x > 0 and y > 0:
        return abs(arctan(y/x)) + pi/2
    elif x == 0 and y > 0:
        return pi
    elif x < 0 and y > 0:
        return abs(arctan(x/y)) + pi
    elif x < 0 and y == 0:
        return 3*pi/2
    elif x < 0 and y < 0:
        return abs(arctan(y/x)) + 3*pi/2

def Visible(a1, a2):
    dx = a2[0] - a1[0]
    dy = a2[1] - a1[1]
    g = gcd(dx,dy)
    dx /= g
    dy /= g
    point = list(a1)
    point[0] += dx
    point[1] += dy
    while tuple(point) != a2:
        if tuple(point) in astroids:
            return False
        point[0] += dx
        point[1] += dy
    return True

def getVisList(a):
    vis = []
    for i in astroids:
        if i != a and Visible(a, i):
            vis += [i]
    return vis

def DESTROY(n, a):
    l = getVisList(a)
    l.sort(key = lambda x: cusAtan(x[0] - a[0], x[1] - a[1]))
    if l == []:
        return
    if len(l) < n:
        for i in l:
            astroids.remove(i)
        return DESTROY(n - len(l), a)

    return(l[n])

astroids = set()

for i, line in enumerate(stdin):
    for j, char in enumerate(line):
        if char == "#":
            astroids.add((j,i))

b = 0

for i in astroids:
    c = 0
    for j in astroids:
        if i != j and Visible(i, j):
            c += 1
    if c > b:
        b = c
        p = i

print(b)
d = DESTROY(200 - 1, p)
print(d[0] * 100 + d[1])