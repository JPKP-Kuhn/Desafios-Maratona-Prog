pontos, medicoes, comp_min = map(int, input().split())

while pontos != 0:
    mat = [None] * medicoes # linha
    for i in range(medicoes):
        mat[i] = [None] * pontos # pontos serão as colunas

    for l in range(len(mat)):
        mat[l] = (list(map(int, input().split())))

    visitados = [[False for _ in range(pontos)] for _ in range(medicoes)]

    # Contar palitos verticais
    palitos = 0
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j] == 1 and not visitados[i][j]:
                tam_palito = 0
                k = i
                # Verificar continuidade vertical
                while k < len(mat) and mat[k][j] == 1 and not visitados[k][j]:
                    tam_palito += 1
                    k += 1
                # Contar apenas se o comprimento for suficiente
                if tam_palito >= comp_min:
                    palitos += 1
                    # Marcar como visitados apenas os que fazem parte do palito válido
                    for m in range(i, i + tam_palito):
                        visitados[m][j] = True

    print(palitos)
                    
    pontos, medicoes, comp_min = map(int, input().split())
