o = input()
mat = []
for i in range(12):
    col = []
    for j in range(12):
        x = float(input())
        col.append(x)
    mat.append(col)

if o == 'S':
    soma=0.0

    for i in range(12):
        for j in range(12):
            if j > 12-i-1:
                soma+=mat[i][j]
    print(f"{soma:.1f}")
elif o == 'M':
    soma=0.0
    c=0
    for i in range(12):
        for j in range(12):
            if j > 12-i-1:
                c+=1
                soma+=mat[i][j]
    media = soma/c
    print(f"{media:.1f}")

