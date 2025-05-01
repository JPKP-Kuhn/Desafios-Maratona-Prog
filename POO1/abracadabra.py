def lista_palavra(lista):
    for i in lista:
        print(i, end="")
    print()

def for_palavra(palavra):
    letras = []
    for i in palavra:
        letras.append(f"{i} ")
    letras[-1] = letras[-1].strip()
    lista_palavra(letras)

    for _ in range(len(letras)-1):
        for i in range(len(letras)-1, 0, -1):
            letras[i] = letras[i-1]
        letras[0] = ' '
        letras[-1] = letras[-1].strip()
        lista_palavra(letras)

    print()

while True:
    try:
        p = input()
        for_palavra(p)
        
    except EOFError:
        break

