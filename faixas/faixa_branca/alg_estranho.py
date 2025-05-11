x = int(input())
r = []
r.append(x)

while x != 1:
    if x % 2 == 0:
        x = x // 2
        r.append(x)
    else:
        x = x * 3 + 1
        r.append(x)

for i in r:
    print(i, end=" ")
