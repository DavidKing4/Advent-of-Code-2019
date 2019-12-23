image = input()

least_zeros = 151

for i in range(0, len(image), 150):
    layer = image[i:i + 150]
    zero_count = 0
    one_count = 0    
    two_count = 0
    for pixel in layer:
        if pixel == "0":
            zero_count += 1
        if pixel == "1":
            one_count += 1
        if pixel == "2":
            two_count += 1
    if zero_count < least_zeros:
        least_zeros = zero_count
        one_two = one_count * two_count

print(one_two)