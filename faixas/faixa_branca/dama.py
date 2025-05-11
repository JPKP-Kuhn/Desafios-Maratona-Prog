# Movimentos da dama num tabuleiro de xadrez

# Verifica se está na mesma diagonal
def diagonal(dama, destino):
    if abs(dama[0] - destino[0]) == abs(dama[1] - destino[1]):
        return True
    else:
        return False


# Movimentos
def movimentos(dama, destino):
    move = 0
    if dama == destino:
        return move
    # Mesma linha ou mesma coluna ou diagonal
    elif dama[0] == destino[0] or dama[1] == destino[1] or diagonal(dama, destino):
        move += 1
        return move
    else:
        move += 2
        return move
        



if __name__ == "__main__":
    tabuleiro = [[0] * 9 for i in range(9)]

    while True:
        entrada = input().split()
        dama = list(map(int, entrada[:2]))
        destino = list(map(int, entrada[2:]))

        tabuleiro[int(dama[0])][int(dama[1])] = 1
        tabuleiro[int(destino[0])][int(destino[1])] = 1

        if int(dama[0]) == 0:
            break

        print(movimentos(dama, destino))

