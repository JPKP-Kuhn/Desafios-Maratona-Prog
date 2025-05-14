import sys

e = sys.stdin.read().splitlines()

lin, col  = map(int, e[0].split())
xr, yr = map(int, e[1].split())

xr-=1 
yr-=1

salao = [None] * lin
visitado = [False] * lin
for i in range(lin):
    salao[i] = [None] * col
    visitado[i] = [False] * col


for i in range(lin):
    salao[i] = (list(map(int, e[2+i].split())))

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]


visitado[xr][yr] = True

movimento_possivel = True
while movimento_possivel:
    movimento_possivel = False

    for d in range(4):
        nx = xr + dx[d]
        ny = yr + dy[d]
        if 0 <= nx < lin and 0 <= ny < col and salao[nx][ny] == 1 and not visitado[nx][ny]:
            xr = nx
            yr = ny

            visitado[nx][ny] = True
            movimento_possivel = True

            break


print(xr+1, yr+1)
