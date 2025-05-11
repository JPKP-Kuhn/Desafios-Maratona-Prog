dobras = int(input())
teste = 0


while dobras != -1:
    teste += 1
    print(f"Teste {teste}")

    pedacos = (2**dobras + 1)**2
    print(pedacos)

    dobras = int(input())
    print()

    
