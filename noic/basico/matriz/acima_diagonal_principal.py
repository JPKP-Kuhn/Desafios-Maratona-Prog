o = input()
mat = []

for i in range(12):
    col = []
    for j in range(12):
        x = float(input())
        col.append(x)
    mat.append(col)

if o == 'S':
    soma=0

    for i in range(12):
        for j in range(12):
            if j <= i:
                continue
            soma+=mat[i][j]
    print(f"{soma:.1f}")
else:
    soma=0
    c=0
    for i in range(12):
        for j in range(12):
            if j <= i:
                continue
            soma+=mat[i][j]
            c+=1
    media = soma/c
    print(f"{media:.1f}")

