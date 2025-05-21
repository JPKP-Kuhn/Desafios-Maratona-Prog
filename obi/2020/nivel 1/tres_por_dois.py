total = int(input())

p_choco = []
for _ in range(total):
    p_choco.append(int(input()))

p_choco.sort(reverse=True)

paga = []
if len(p_choco) >= 3:
    for i in range(0, len(p_choco), 3):
        if i + 2 < len(p_choco):
            paga.append(p_choco[i] + p_choco[i + 1])
        else:
            paga.append(p_choco[i])
            if i + 1 < len(p_choco):
                paga.append(p_choco[i + 1])
else:
    paga = p_choco.copy()

soma = 0
for i in paga:
    soma += i
print(soma)
