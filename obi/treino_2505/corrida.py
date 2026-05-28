n, d, v = map(int, input().split())
x, y, z = map(int, input().split())

# v = d/t, t = d/v

ta = d/v
tb = y/z

if ta < tb:
    print(n)
else:
    print(x)

