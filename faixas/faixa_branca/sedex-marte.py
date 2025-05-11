from math import pi, sqrt

def cabe_esfera(caixa, raio):
    soma_caixa = 0

    for i in caixa:
        soma_caixa += int(i)**2
    diagonal_caixa = sqrt(soma_caixa)

    return 'S' if diagonal_caixa <= raio*2 else 'N'

entrada = input().split()
caixa = [entrada[0], entrada[1], entrada[2]]
raio = int(entrada[-1])

print(cabe_esfera(caixa, raio))
