import sys

# Lendo a entrada do arquivo redirecionado
entrada = sys.stdin.read().splitlines()

# Número de cartelas, números em cada cartela e maior natural nas cartelas
n, k, u = map(int, entrada[0].split())

cartelas = {}
for i in range(n):
    numeros = list(map(int, entrada[i + 1].split()))
    cartelas[i + 1] = numeros

sorteado = list(map(int, entrada[-1].split()))

def bingo(cartelas):
    vencedoras = []  # Lista para armazenar as cartelas vencedoras
    for i in sorteado:
        numero = int(i)
        for k, j in cartelas.items():
            # Verifica em cada número de cartela, se o número i sorteado está na cartela k iterando por cada número j da cartela
            if numero in j:
                index = j.index(numero)
                cartelas[k][index] = "x"
        # Verifica se a cartela tem todos os números marcados com "x"
        vencedoras = [k for k,j in cartelas.items() if all(x == "x" for x in j)]
        if vencedoras:
            break
    return ' '.join(str(i) for i in vencedoras)
            
print(bingo(cartelas))
