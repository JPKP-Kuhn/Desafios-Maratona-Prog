mat = [0] * 12
for i in range(12):
    mat[i] = [0] * 12

o = input()

for i in range(len(mat)):
    for j in range(len(mat[i])):
        mat[i][j] = float(input())

        
def soma(mat):
    soma = 0
    for i in range(1, 11):
        soma+= mat[0][i]

    for i in range(2, 10):
        soma+= mat[1][i]

    for i in range(3, 9):
        soma+= mat[2][i]

    for i in range(4, 8):
        soma+= mat[3][i]

    for i in range(5, 7):
        soma+= mat[4][i]

    return soma

def media(mat):
    soma = 0
    count = 0
    for i in range(1, 11):
        soma+= mat[0][i]
        count+=1

    for i in range(2, 10):
        soma+= mat[1][i]
        count+=1

    for i in range(3, 9):
        soma+= mat[2][i]
        count+=1

    for i in range(4, 8):
        soma+= mat[3][i]
        count+=1

    for i in range(5, 7):
        soma+= mat[4][i]
        count+=1

    return soma / count




if o == 'S':
    valor = soma(mat)
else:
    valor = media(mat)

print("{:.1f}".format(valor))
