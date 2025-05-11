n = int(input())

def arruma_lista(lista):
    if len(lista) == 1:
        return lista[0]
    else:
        texto = ""
        for i in lista:
            if i != lista[-1]:
                texto += f"{str(i)}, "
            else:
                texto += f"{str(i)}"
        return texto


while n != 0:
    re_pilha = []
    de_pilha = []
    for i in range(n):
        re_pilha.append(i+1)

    while len(re_pilha) > 1:
        de_pilha.append(re_pilha.pop(0))
        re_pilha = re_pilha[1:] + re_pilha[:1]


    print(f"Discarded cards: {arruma_lista(de_pilha)}")
    print(f"Remaining card: {arruma_lista(re_pilha)}")

    n = int(input())
