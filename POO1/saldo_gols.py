n = int(input())
teste=1
while(n>0):
    inicio, fim = 0, 0
    temp_inicio=0
    maxSoma=-1
    soma=0
    for i in range(n):
        x, y = map(int, input().split())
        saldo = x-y

        soma+=saldo

        if soma<0:
            temp_inicio=i+1
            soma=0
        else:
            if (soma > maxSoma) or (soma == maxSoma and fim - inicio < i-temp_inicio):
                maxSoma=soma
                inicio=temp_inicio
                fim=i

    print(f"Teste {teste}")
    if maxSoma <= 0:
        print("nenhum")
    else:
        print(inicio+1, fim+1)
    print()
    teste+=1
    n = int(input())
