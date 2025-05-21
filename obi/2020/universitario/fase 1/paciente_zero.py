# Determinar quem foi o primeiro paciente da infecção
tot_infect, tot_cadeias = map(int, input().split())
fonte = []
infect = []

for i in range(tot_cadeias):
    cadeias = input().split()
    cadeias.pop(1)
    if cadeias[0] not in fonte:
        fonte.append(cadeias[0])
    cadeias.pop(0)
    infect.extend(cadeias)

resposta = []
for i in fonte:
    if not i in infect:
        resposta.append(i)

resposta = [int(k) for k in resposta]
resposta.sort()
for i in resposta:
    print(i)


