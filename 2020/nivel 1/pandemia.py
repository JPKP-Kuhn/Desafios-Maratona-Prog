# Descobrir quantos amigos foram infectados
import sys
e = sys.stdin.read().splitlines()

tot_amigos, tot_dReuniao = map(int, e[0].split())
amg_infec, r_amg_infec = map(int, e[1].split())

participantes_r = dict()
linha_atual = 2

for i in range(tot_dReuniao):
    dados = list(map(int, e[linha_atual].split()))
    num_participantes = dados[0]  # O primeiro número é a quantidade de participantes
    participantes = dados[1:]     # Os demais números são os IDs dos participantes
    participantes_r[i+1] = participantes
    linha_atual += 1

# Procura por infectados
infectados = set()

# Se algum elemento de infectados está nos participantes da reunião, então todos são adicionas no set
for i, k in participantes_r.items():
    # Para a reunião que o amigo for infectado
    if i == r_amg_infec:
        infectados.add(amg_infec)

    if any(j in k for j in infectados.copy()):
        infectados.update(k)

print(len(infectados))

