n, m = map(int, input().split())
linhas, colunas = [], []
variaveis = {}
mat = [None]

for i in range(n+1):
    for j in range(m+1):
        valor = input()
        if i == n:
            linhas.append(int(valor))
        if j == m:
            colunas.append(int(valor))
