# Verificar a erupção de um vulcão
import sys

e = sys.stdin.read().splitlines()

n, f = map(int, e[0].split())
del e[0]

# Matriz do terreno
mat = [None] * n
for i in range(n):
    mat[i] = list(map(int, e[i]))

# Lista de teste para controlar a propagação da lava
lista = []
if mat[0][0] <= f:
    mat[0][0] = '*'
    lista.append((0,0))

# Para verificar as direções: para cima (-1, 0), para direita (0, 1), baixo (1, 0) e esquerda (0, -1)
dy = [-1, 0, 1, 0] # São vetores de direção
dx = [0, 1, 0, -1]

# Algoritimo de busca em largura (BFS) para simular a propagação de lava
while lista != []:
    u = lista.pop(0) # retira o primeiro elemento, FIFO
    i, j = u[0], u[1] # coordenadas atuais

    # Verifica as 4 direções adjacentes
    for d in range(4):
        iv = i + dy[d] # Nova coordenada y
        jv = j + dx[d] # Nova coordenada x

        # Verifica se a nova posição está dentro dos limites da matriz
        if iv >= 0 and iv <= n-1 and jv >= 0 and jv <= n-1:
            if mat[iv][jv] != '*' and mat[iv][jv] <= f:
                mat[iv][jv] = '*'
                lista.append((iv, jv)) # Adiciona a nova posição a lista de propagação


def converte_saida(matriz):
    return '\n'.join(''.join(map(str, linha)) for linha in matriz)
print(converte_saida(mat))
