# Dada uma lista, determinar os bilhetes falsos

bilhetes_originais, pessoas = map(int, input().split())

while bilhetes_originais != 0 and pessoas !=0:
    n_bilhetes = list(map(int, input().split()))

    copia = []
    original = []
    for i in n_bilhetes:
        if i not in original:
            original.append(i)
        else:
            if i not in copia:
                copia.append(i)

    print(len(copia))
    bilhetes_originais, pessoas = map(int, input().split())

