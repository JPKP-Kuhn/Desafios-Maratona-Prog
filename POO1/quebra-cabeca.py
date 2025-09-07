n, m = map(int, input().split())
linhas, colunas = [], []
mat = []

for _ in range(n):
    valor = input().split()
    linha = valor[:m]
    soma = int(valor[m])
    mat.append(linha)
    linhas.append(soma)

colunas = list(map(int, input().split()))

variaveis = {v for i in mat for v in i}
valores = dict()

while len(valores) < len(variaveis):
    # verificar linhas
    for i in range(n):
        soma = linhas[i]
        desconhecida = []
        soma_conhecida = 0
        for j in range(m):
            var = mat[i][j]
            if var in valores:
                soma_conhecida += valores[var]
            else:
                desconhecida.append(var)
        if len(desconhecida) > 0 and all(v == desconhecida[0] for v in desconhecida):
            var = desconhecida[0]
            valores[var] = (soma - soma_conhecida) // len(desconhecida)

    # verificar colunas
    for j in range(m):
        soma = colunas[j]
        desconhecida = []
        soma_conhecida = 0
        for i in range(n):
            var = mat[i][j]
            if var in valores:
                soma_conhecida += valores[var]
            else:
                desconhecida.append(var)
        if len(desconhecida) > 0 and all(v == desconhecida[0] for v in desconhecida):
            var = desconhecida[0]
            valores[var] = (soma - soma_conhecida) // len(desconhecida)

for v in sorted(variaveis):
    print(v, valores[v])

