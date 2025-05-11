from math import pi

def cabe_caixa(diametro, caixa):
    volume_esfera = 4/3 * pi * (diametro/2)**3
    volume_caixa = 1

    for i in caixa:
        volume_caixa *= int(i)
        if int(i) < diametro:
            return 'N'
    
    return 'S' if volume_esfera < volume_caixa else 'N'



diametro = int(input())
caixa = input().split()

print(cabe_caixa(diametro, caixa))

