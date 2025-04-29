# Verificar se um cpf é válido ou não
import sys

cpf = sys.stdin.readlines()
for i in range(len(cpf)):
    cpf[i] = cpf[i].replace('\n', '')


def verifica_cpf(cpf):
    cpf = cpf.replace('-', '').replace('.', '')

    digitos = [int(n) for n in cpf]

    verificacao1 = 0
# Multiplica o primeiro por 1, segundo por 2, ...
    for i in range(9):
        verificacao1 += digitos[i] * (i+1)

    teste1 = 0 if verificacao1 % 11 == 10 else verificacao1 % 11

    verificacao2 = 0
# Muktiplica o primeiro por 9, segundo por 8, ...
    for i in range(9):
        verificacao2 += digitos[i] * (9-i)

    teste2 = 0 if verificacao2 % 11 == 10 else verificacao2 % 11

    if teste1 == digitos[-2] and teste2 == digitos[-1]:
        print("CPF valido")
    else:
        print("CPF invalido")


for i in range(len(cpf)):
    verifica_cpf(cpf[i])
