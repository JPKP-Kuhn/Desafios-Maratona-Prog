while True:
    try:
        n = int(input())

        matriz = [0] * n
        for i in range(n):
            matriz[i] = [0] * n

        for i in range(len(matriz)):
            matriz[i][i] = 2
            matriz[i][n - 1 - i] = 3


        for i in range(n//3, n - n//3):
            for j in range(n//3, n - n//3):
                matriz[i][j] = 1

        # Valor central
        linha_meio = len(matriz)//2
        coluna_meio = len(matriz[linha_meio])//2
        matriz[linha_meio][coluna_meio] = 4

        # Saída
        for i in range(len(matriz)):
            for j in range(len(matriz[i])):
                print(matriz[i][j], end=' ')
                if j == len(matriz)-1:
                    print()

    except EOFError:
        break
