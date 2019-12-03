p1 = input().split(",")
p2 = input().split(",")

p = [p1, p2]
s = [set(), set()]

for k in [0, 1]:
    c = [0,0]
    for i in p[k]:
        if i[0] == "U":
            for j in range(int(i[1:])):
                c[1] += 1
                s[k].add((c[0], c[1]))
        if i[0] == "R":
            for j in range(int(i[1:])):
                c[0] += 1
                s[k].add((c[0], c[1]))
        if i[0] == "D":
            for j in range(int(i[1:])):
                c[1] -= 1
                s[k].add((c[0], c[1]))
        if i[0] == "L":
            for j in range(int(i[1:])):
                c[0] -= 1
                s[k].add((c[0], c[1]))
        
u = s[0].intersection(s[1])

best = 100000000000
for i in u:
    t = abs(i[0]) + abs(i[1])
    if t < best:
        best = t
        
print(best)