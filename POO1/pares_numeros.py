n, i, f = map(int, input().split())
v = list(map(int, input().split()))

c=0
for x in range(n):
    for y in range(n):
        if (x == y):
            continue
        soma = v[x] + v[y]
        if (i <= soma and soma <= f):
            c+=1

print(c//2)
