# Calcular as áreas que serão invadidas pela lava
import sys

e = sys.stdin.read().splitlines()

m, v = map(int, e[0].split())
del e[0]

lava = []

for i in e:
    lista = [int(j) for j in i]
    lava.append(lista)

# Agora verifica fissura e o avanço da lava
def escoa_lava(v, lava):
    if v < lava[0][0]:
        return lava
    else:
        for i in range(len(lava)):
            for j in range(len(lava[i])):
                if v >= lava[i][j] and lava[i][j] != '*':
                    lava[i][j] = '*'
                    # Verifica se a lava pode avançar para a direita
                    if j + 1 < len(lava[i]) and lava[i][j+1] > v:
                        break
                    # Verifica se a lava pode avançar para cima e/ou esquerda
                    if i - 1 >= 0 and isinstance(lava[i-1][j], int) and lava[i-1][j] <= v :
                        lava[i-1][j] = '*'
                        if j - 1 >= 0 and isinstance(lava[i-1][j-1], int) and lava[i-1][j-1] <= v:
                            lava[i-1][j-1] = '*'
        # Verifica do último para o primeiro
        if not lava[-1][-1] == '*' and (lava[-1][-2] > v and lava[-2][-1] > v):
            return lava
        else:
            for i in range(len(lava)-1, -1, -1):
                for j in range(len(lava[i])-1, -1, -1):
                    # Procurar pela lava, *
                    if lava[i][j] == '*':
                        break
                    # Verifica se tem lava na linha de baixo
                    elif not lava[i-1][j] == '*' and lava[i][j] <= v:
                        lava[i][j] = '*'

        
        return lava


def converte_saida(matriz):
    return '\n'.join(''.join(map(str, linha)) for linha in matriz)


# Chama a função para calcular a lava
lava = escoa_lava(v, lava)
# Converte a saída para o formato desejado
saida = converte_saida(lava)
print(saida)

