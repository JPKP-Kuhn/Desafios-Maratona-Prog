# Somar número, o 0 vai retirar o último número adicionado
n = int(input())

soma = [0]
for _ in range(n):
    entrada = int(input())
    
    if entrada == 0:
        soma.pop()
    else:
        soma.append(entrada)

total = 0
for i in soma:
    total += i 

print(total)
