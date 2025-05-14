n = int(input())

numeros = list(map(int, input().split()))
"""
Assim não é eficiente:
naturais = []

for i in range(1, n+1):
    naturais.append(i)

print(naturais)
"""
soma = 0;
for i in numeros:
    soma+=i

total = int((n*(n+1))/2)
print(total - soma)

