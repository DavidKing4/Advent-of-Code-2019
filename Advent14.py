from sys import stdin
from math import ceil

recip_book, made, cost = {}, {}, 0

for line in stdin:
    product = line.split(" => ")[1]
    materials = line.split(" => ")[0]
    recip_book[product.split()[1]] = [product.split()[0]] + list(map(lambda x: x.split(), (materials.split(", "))))
    made[product.split()[1]] = 0

def find_cost(product = "FUEL", need = 1):

    global cost
    global made
    makes = int(recip_book[product][0])
    batches = ceil(need/makes)

    for i in recip_book[product][1:]:
        material = i[1]
        for_one = int(i[0])
        material_need = batches * for_one

        if material == "ORE":
            cost += material_need
            continue

        if material in made:
            if material_need >= made[material]:
                material_need -= made[material]
                made[material] = 0
            else:
                made[material] -= material_need
                material_need = 0


        find_cost(material, material_need)

    waste = (batches * int(recip_book[product][0])) - need
    if product in made:
        made[product] += waste
    else:
        made[product] = waste

find_cost()
print(cost)

cost = 0
made = {}
#i = 2362000
i = 2371000
#find_cost(need = 2362000)
find_cost(need = 2371000)

while cost < 1000000000000: #manual search keep reducing i til its 1
    find_cost(need = 1)
    i += 1

print(i - 1)