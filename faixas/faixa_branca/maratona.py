import sys

e = sys.stdin.read().splitlines()

postos, dist_inter = map(int, e[0].split())

agua = list(map(int, e[1].split()))

def corrida(agua):
    for i in range(len(agua)-1):
        if agua[i+1] - agua[i] > dist_inter:
            return 'N'
    return 'S'

print(corrida(agua))
