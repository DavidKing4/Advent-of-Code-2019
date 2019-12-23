from sys import stdin


def new_stack(cards):
    cards.reverse()
    return cards


def cut(n, cards):
    if n < 0:
        n += 10007
    return (cards[n:] + cards[:n])


def with_increment(n, cards):
    new = [0 for i in range(10007)]
    for i, j in enumerate(range(0, n*10007, n)):
        new[j % 10007] = cards[i]
    return(new)


deck = list(range(10007))

for line in stdin:
    if line[:len(line) - 1] == "deal into new stack":
        deck = new_stack(deck)
    elif line.split()[0] == "cut":
        deck = cut(int(line.split()[1]), deck)
    elif line.split()[0] == "deal":
        deck = with_increment(int(line.split()[3]), deck)

for i, c in enumerate(deck):
    if c == 2019:
        print(i)