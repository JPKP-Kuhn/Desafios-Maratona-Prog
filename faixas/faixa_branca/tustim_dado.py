teste = int(input())

while teste > 0:
    lados = []
    frow = int(input())
    lados.append(frow)

    mrow = list(map(int, input().split()))
    lados.extend(mrow)

    lrow = int(input())
    lados.append(lrow)


    dados = sorted(lados) == [1, 2 ,3 ,4 ,5, 6]
    soma = (lados[0] + lados[5] == 7) and (lados[1] + lados[3] == 7) and (lados[2] + lados[4] == 7)

    if soma and dados:
        print("SIM")
    else:
        print("NAO")


    teste -= 1
