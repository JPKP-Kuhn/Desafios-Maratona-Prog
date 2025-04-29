# Lista de múltiplos de 2, 3, 4, 5

def multiplos(lista):
    n2 = n3 = n4 = n5 = 0
    for i in lista:
        if i % 2 == 0:
            n2+=1
        if i % 3 == 0:
            n3+=1
        if i % 4 == 0:
            n4+=1
        if i % 5 == 0:
            n5+=1

    return f"""{n2} Multiplo(s) de 2
{n3} Multiplo(s) de 3
{n4} Multiplo(s) de 4
{n5} Multiplo(s) de 5"""
n = int(input())
lista = list(map(int, input().split()))
print(multiplos(lista))
