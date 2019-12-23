from sympy import symbols, Poly


def new_stack(x, p):
    return (p - 1 - x);


def cut(x, n, p):
    return (x + n) if n > 0 else (x + n + p)


def with_increment(x, n, p):
    return (x * pow(n, p - 2, p))


def reduce(a, b, n):
    if n == 1:
        return a, b
    elif n % 2 == 0:
        return reduce((a**2) % p, (a*b + b) % p, n/2)
    else:
        c, d = reduce(a, b, n-1)
        return (a * c) % p, ((a * d) + b) % p

## "ax+b" N times is the same as "a^2*x + ab+b" N/2 times
## thanks reddit


file = list(reversed(list(open("day22.txt"))))
x = symbols("x")
p = 119315717514047
n = 101741582076661

for line in file:
    if line[:len(line) - 1] == "deal into new stack":
        x = new_stack(x, p)
    elif line.split()[0] == "cut":
        x = cut(x, int(line.split()[1]), p)
    elif line.split()[0] == "deal":
        x = with_increment(x, int(line.split()[3]), p)

lin = Poly(x, symbols("x"))
a, b = lin.all_coeffs()
x = (a % p) * symbols("x") + (b % p)
print(x % p)

a, b = reduce(a, b, n)
x = (a % p) * symbols("x") + (b % p)
print(x % p)
print(((a * 2020) + b) % p)