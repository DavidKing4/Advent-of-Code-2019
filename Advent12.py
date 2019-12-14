from numpy import lcm

moons = [[17, -7, -11, 0, 0, 0], [1, 4, -1, 0, 0, 0], [6, -2, -6, 0, 0, 0], [19, 11, 9, 0, 0, 0]]
#moons = [[-1, 0, 2, 0, 0, 0],[2, -10, -7, 0, 0, 0],[4, -8, 8, 0, 0, 0],[3, 5, -1, 0, 0, 0]]
#moons = [[-8, -10, 0, 0, 0, 0],[5, 5, 10, 0, 0, 0],[2, -7, 3, 0, 0, 0],[9, -8, -3, 0, 0, 0]]

def update():
    for i in range(4):
        for j in range(i):
            for k in range(3):
                if moons[i][k] > moons[j][k]:
                    moons[j][k + 3] += 1
                    moons[i][k + 3] -= 1
                if moons[i][k] < moons[j][k]:
                    moons[i][k + 3] += 1
                    moons[j][k + 3] -= 1

    for body in moons:
        for i in range(3):
            body[i] += body[i + 3]


for i in range(1000):
    update()

energy = 0
for i in moons:
    map(abs, i)
    energy += sum(list(map(abs, i[:3])))*sum(list(map(abs, i[3:])))
print(energy)

moons = [[17, -7, -11, 0, 0, 0],[1, 4, -1, 0, 0, 0],[6, -2, -6, 0, 0, 0],[19, 11, 9, 0, 0, 0]]
# moons = [[-1, 0, 2, 0, 0, 0],[2, -10, -7, 0, 0, 0],[4, -8, 8, 0, 0, 0],[3, 5, -1, 0, 0, 0]]
# moons = [[-8, -10, 0, 0, 0, 0],[5, 5, 10, 0, 0, 0],[2, -7, 3, 0, 0, 0],[9, -8, -3, 0, 0, 0]]
period = [0,0,0]

i = 0
while True:
    update()
    i += 1
    for j in range(3):
        if False not in [x == 0 for x in [moons[y][j + 3] for y in range(4)]] and period[j] == 0:
            period[j] = i*2
            if 0 not in period:
                break
    else:
        continue
    break

print(f"take lcm of {period}")