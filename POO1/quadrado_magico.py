mat = []
soma_magica=0
for i in range(3):
    col = list(map(int, input().split()))
    if 0 not in col:
        soma_magica = sum(col)

    mat.append(col)
if soma_magica==0:
    for i in range(3):
        c=[]
        for j in range(3):
            c.append(mat[j][i])
        if 0 not in c:
            soma_magica = sum(c)
            break
if soma_magica==0:
    c=[]
    for i in range(3):
        c.append(mat[i][i])
    if 0 not in c:
        soma_magica=sum(c)
if soma_magica==0:
    c=[]
    for i in range(3):
        c.append(mat[i][3-i-1])
    if 0 not in c:
        soma_magica=sum(c)
if soma_magica==0:
    soma=0
    for i in range(3):
        for j in range(3):
            soma+=mat[i][j]
    soma_magica=soma//2

#print("A soma mágica é", soma_magica)
cima = False
for i in range(3):
    c = mat[i]
    cz=0
    for _ in range(3):
        if c[_]==0:
            cz+=1
    if cz<=1 and not cima:
        falta = soma_magica-sum(c)
        if falta > 0:
            for j in range(3):
                if mat[i][j] == 0:
                    mat[i][j]=falta
    else:
        l = []
        cima = True
        for j in range(3):
            l.append(mat[j][i])
        falta = soma_magica-sum(l)
        if falta > 0:
            for j in range(3):
                if mat[j][i] == 0:
                    mat[j][i]=falta

for i in range(3):
    l = []
    for j in range(3):
        l.append(mat[j][i])
    if 0 in l:
        falta = soma_magica-sum(l)
        if falta > 0:
            for j in range(3):
                if mat[j][i]==0:
                    mat[j][i]=falta


for i in range(3):
    for j in range(3):
        if j != 2:
            print(mat[i][j], end=' ')
        else:
            print(mat[i][j])


