n, c = map(int, input().split())

atual = 0
f = False
for _ in range(n):
    s, e = map(int, input().split())
    atual -= s
    atual += e

    if atual > c:
        f = True
if (f):
    print("S")
else:
    print("N")
