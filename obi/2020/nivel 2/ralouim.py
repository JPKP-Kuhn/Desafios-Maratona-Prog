# Ganahr mais guloseimas nas tendas de doces
from math import *

tot_tendas = int(input())

palacio = (0,0)

tendas = {}
for i in range(1, tot_tendas+1):
    tendas[i] = tuple(map(int, input().split()))

guloseima = 0
# As coordenadas das tendas formam um plano cartesiano
# A distância percorrida entra as barracas deve ser decrescente

def tenda_mais_distante(tendas):
    tenda_longe = None
    maior_dist = 0

    for i, k in tendas.items():
        dist = sqrt(pow(k[0], 2) + pow(k[1], 2))

        if dist > maior_dist:
            maior_dist = dist
            tenda_longe = (i, k, dist)

    return tenda_longe

# Primeira tenda a vistiar, a mais longe 
tenda_longe, coord_tenda_longe, dist_tenda_longe = tenda_mais_distante(tendas)
guloseima += 1

