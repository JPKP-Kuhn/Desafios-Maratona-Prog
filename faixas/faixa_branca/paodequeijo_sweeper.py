import sys

e = sys.stdin.read().splitlines()

while len(e):
    n, m = map(int, e[0].split())
    del e[0]

    mat = [0] * n
    for i in range(n):
        mat[i] = list(map(int, e[0].split()))
        del e[0]

    tabuleiro = [0] * n
    for i in range(n):
        tabuleiro[i] = [0] * m

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    pao = 0
    for i in range(n):
        for j in range(m):
            if mat[i][j] == 1:
                tabuleiro[i][j] = 9
            else:
                for d in range(4):
                    nx = dx[d] + i
                    ny = dy[d] + j

                    if 0 <= nx < n and 0<= ny < m:
                        if mat[nx][ny]:
                            pao+=1
                tabuleiro[i][j] = pao
                pao = 0


    for i in range(n):
        for j in range(m):
            print(tabuleiro[i][j], end='')
        print()




