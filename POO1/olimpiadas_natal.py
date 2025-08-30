paises = {}

def ordem(item):
    pais, (ouro, prata, bronze) = item
    return (-ouro, -prata, -bronze, pais)


while True:
    try:
        prova = input()
        for i in range(3):
            pais = input()
            if pais not in paises:
                paises[pais] = [0, 0, 0]
            if i == 0:
                paises[pais][i]+=1
            if i==1:
                paises[pais][i]+=1
            if i==2:
                paises[pais][i]+=1
    except EOFError:
        break

print("Quadro de Medalhas")
for k, v in sorted(paises.items(), key=ordem):
    print(f"{k} {v[0]} {v[1]} {v[2]}")

