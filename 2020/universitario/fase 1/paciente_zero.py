# Determinar quem foi o primeiro paciente da infecção
tot_infect, tot_cadeias = map(int, input().split())

cadeias = []
for i in range(tot_cadeias):
    cadeias.append(list(map(int, input().split())))
# Remove o segundo índice de cada cadeia
for i in cadeias:
    i.pop(1)

fonte = [] # A fonte de cada cadeia
for j in range(len(cadeias)):
    fonte.append(cadeias[j][0])

# Remove a fonte da cadeia
for i in cadeias:
    i.pop(0)

# Porcurar se alguma das fontes na está na cadeia de outra fonte
for i in fonte:
    for j in range(len(cadeias)):
        if i in cadeias[j]:
            fonte.remove(i)

fonte.sort()
for i in fonte:
    print(i)
