p1 = input().split(",")
p2 = input().split(",")

p = [p1, p2]
s = [set(), set()]
d = [{},{}]


for k in [0, 1]:
    c = [0,0]
    t = 0
    for i in p[k]:
        if i[0] == "U":
            for j in range(int(i[1:])):
                t += 1
                c[1] += 1
                s[k].add((c[0], c[1]))
                d[k][(c[0], c[1])] = t
        if i[0] == "R":
            for j in range(int(i[1:])):
                t += 1
                c[0] += 1
                s[k].add((c[0], c[1]))
                d[k][(c[0], c[1])] = t
        if i[0] == "D":
            for j in range(int(i[1:])):
                t += 1
                c[1] -= 1
                s[k].add((c[0], c[1]))
                d[k][(c[0], c[1])] = t
        if i[0] == "L":
            for j in range(int(i[1:])):
                t += 1
                c[0] -= 1
                s[k].add((c[0], c[1]))
                d[k][(c[0], c[1])] = t
        
u = s[0].intersection(s[1])

best = 100000000000
for i in u:
    t = d[0][i] + d[1][i]
    if t < best:
        best = t
    
print(best)