import sys
from collections import deque

e = sys.stdin.read().splitlines()

n = int(e[0])
del e[0]
aluno = list(map(int, e[0].split()))
inx = aluno[0]-1
iny = aluno[1]-1
del e[0]

mat = [0] * n
banderia = [False] * n
for i in range(n):
    mat[i] = list(map(int, e[0].split()))
    banderia[i] = [False] * n
    del e[0]

# Recebeu a bolinha
banderia[inx][iny] = True
fila = deque([(inx, iny)])

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

count = 1

while fila:
    x, y = fila.popleft()

    for i in range(4):
        nx = dx[i] + x
        ny = dy[i] + y

        if (0 <= nx < n and 0 <= ny < n) and (mat[nx][ny] >= mat[x][y] and not banderia[nx][ny]):
            banderia[nx][ny] = True
            fila.append((nx, ny))
            count+=1

print(count)

