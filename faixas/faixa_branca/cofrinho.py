deposito = int(input())
teste = 0

while deposito != 0:
    diferenca = 0
    teste += 1

    print(f"Teste {teste}")

    for i in range(0, deposito):
        j, z = map(int, input().split())
        diferenca += j - z
        print(diferenca)

    deposito = int(input())
    print()




