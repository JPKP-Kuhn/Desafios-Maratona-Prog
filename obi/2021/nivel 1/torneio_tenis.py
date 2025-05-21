partidas = []
for _ in range(6):
    partidas.append(input())


vitorias = partidas.count('V')
if vitorias >= 5:
    print(1)
elif vitorias >= 3:
    print(2)
elif vitorias >= 1:
    print(3)
else:
    print(-1)
