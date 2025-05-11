e = input()
cartas = []

for i in range(0, len(e), 3):
    cartas.append(e[i:i+3])

baralho = {
    'C': [],
    'E': [],
    'U': [],
    'P': []
}

for carta in cartas:
    if 'C' in carta:
        baralho['C'].append(carta[:2])
    elif 'E' in carta:
        baralho['E'].append(carta[:2])
    elif 'U' in carta:
        baralho['U'].append(carta[:2])
    elif 'P' in carta:
        baralho['P'].append(carta[:2])

def ver_repetido(carta):
    teste = set()
    teste.add(carta)

    print(f"Meu set: {teste}")
    return len(teste)


for k, v in baralho.items():
    teste = ver_repetido(carta)
    print(13 - len(v))

