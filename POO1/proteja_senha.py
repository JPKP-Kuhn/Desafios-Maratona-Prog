teste = 1
while True:
    n = int(input())
    if n == 0:
        break

    botoes = []
    palavras = []

    for i in range(n):
        entrada = list(input().split())
        nums = list(map(int, entrada[:10]))
        linha_botoes = []
        for j in range(0, 10, 2):
            linha_botoes.append({nums[j], nums[j+1]})
        botoes.append(linha_botoes)
        palavras.append(entrada[10:16])

    senha=''
    for l in range(6):
        temp_set = set()
        for i in range(n):
            letra = palavras[i][l]
            idx = ord(letra)-ord('A')
            bnums = botoes[i][idx]
            if len(temp_set) == 0:
                temp_set = set(bnums)
            else:
                temp_set &= bnums
        numero = temp_set.pop()
        senha+=str(numero)

    print(f"Teste {teste}")
    for s in senha:
        print(s, end=' ')
    print()
    print()
    teste+=1

