# Música para todoos ficarem satisfeitos = não é a detestada
tot_amigos, tot_musicas, musica = map(int, input().split())

amigos = []
for i in range(tot_amigos):
    amigos.append(list(map(int, input().split())))


trocas = 0
# Verifica se alguém detesta a música atual
def gosto(amigos, musica, trocas):
    for i in range(len(amigos)):
        if amigos[i][1] == musica:
            trocas += 1
            nova_musica = amigos[i][0]
            if trocas == tot_musicas:
                return -1
            return gosto(amigos, nova_musica, trocas)  # Retorna imediatamente após uma troca
    return trocas  # Retorna trocas apenas se nenhuma troca foi feita

print(gosto(amigos, musica, trocas))



