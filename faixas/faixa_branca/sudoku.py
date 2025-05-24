import sys

e = sys.stdin.read().splitlines()
n = int(e[0])
del e[0]
test = 0

# Verifica a matriz de Sudoku
def ver_sudoku(sudoku):
    # Verifica cada linha
    for i in range(len(sudoku)):
        for j in range(1, 10):
            v = sudoku[i].count(j)
            if v > 1:
                return "NAO"

    # Verifica cada coluna
    for i in range(len(sudoku)):
        coluna = []  # Reinicia a lista para cada coluna
        for j in range(len(sudoku)):
            coluna.append(sudoku[j][i])  # Adiciona o elemento da coluna atual

        for k in range(1, 10):
            c = coluna.count(k)
            if c > 1:
                return "NAO"

    # Verifica cada quadrante 3x3
    for i in range(3):
        for j in range(3):
            quadrante = []
            for k in range(3):
                for l in range(3):
                    quadrante.append(sudoku[i * 3 + k][j * 3 + l])  # Adiciona o elemento do quadrante atual
            for m in range(1, 10):
                q = quadrante.count(m)
                if q > 1:
                    return "NAO"

    return "SIM"

while n != 0:
    test += 1
    n -= 1
    sudoku = []

    # Lê a matriz de Sudoku
    for i in range(9):
        sudoku.append(list(map(int, e[0].split())))
        del e[0]

    result = ver_sudoku(sudoku)
    print("Instancia", test)
    print(result)
    print()
