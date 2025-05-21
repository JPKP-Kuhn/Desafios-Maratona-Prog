import sys

def saida_bateu(bateu):
    print(f"BOOM {bateu[0]} {bateu[1]}")

# Ler todas as linhas da entrada
e = sys.stdin.read().strip().split("\n")

while True:
    # Ler L, C, P
    l, c, p = map(int, e[0].split())
    del e[0]
    if l == 0 and c == 0 and p == 0:
        break

    # Ler a matriz
    mat = []
    for _ in range(l):
        mat.append(list(map(int, e[0].split())))
        del e[0]

    bateu = []
    p -= 1  # Ajustar índice da coluna para 0-based

    for linha_atual in range(l):
        mat[linha_atual][p] = -1  # Entrada do balão

        # Descobre o ventilador mais à direita e o mais à esquerda a partir da posição do balão
        vent_dir = 0
        for i in range(p + 1, len(mat[linha_atual])):
            if mat[linha_atual][i] != 0:
                vent_dir = mat[linha_atual][i]
                break

        vent_esq = 0
        for i in range(p - 1, -1, -1):
            if mat[linha_atual][i] != 0:
                vent_esq = mat[linha_atual][i]
                break

        # Andar a diferença dos ventiladores
        dx = abs(vent_esq - vent_dir)
        if vent_dir > vent_esq:
            for i in range(p, p - dx - 1, -1):
                if mat[linha_atual][i] > 0:
                    bateu = [linha_atual + 1, i + 1]
                    saida_bateu(bateu)
                    break
                else:
                    mat[linha_atual][i] = -1
            if bateu:
                break
            p -= dx  # Para a nova coluna do balão
        elif vent_esq > vent_dir:
            for i in range(p, p + dx + 1):
                if mat[linha_atual][i] > 0:
                    bateu = [linha_atual + 1, i + 1]
                    saida_bateu(bateu)
                    break
                else:
                    mat[linha_atual][i] = -1
            if bateu:
                break
            p += dx  # Nova coluna do balão

    if not bateu:
        print(f"OUT {p + 1}")


