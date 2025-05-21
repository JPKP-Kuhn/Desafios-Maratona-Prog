# Determinar o tempo de resposta de cada mensagem
import sys

entrada = sys.stdin.read().splitlines()
registros = int(entrada[0])
del entrada[0]

amigos = {}
resposta = []
amigo_sem_resposta = set()

# Primeiro recebe a R e identifica o amigo, assim fica somando o tempo mais até que apareça um E amigo e assim print(amigo, tempo) 
for i in range(registros):
    e = entrada[0].split()
    del entrada[0]

    match e[0]:
        case 'R': # Registra novo amigo_id
            amigo_id = int(e[1])
            amigos[amigo_id] = [0, 0] # 1º é pro T, 2º pro segundos após R
            amigo_sem_resposta.add(amigo_id)
            
            for i, k in amigos.items():
                if i != amigo_id:
                    k[1] += 1

        case 'E': # print amigo e tempo de resposta
            amigo_id = int(e[1])
            if amigo_id in amigos:
                resposta.append([amigo_id, amigos[amigo_id][0] + amigos[amigo_id][1]])
            if amigo_id in amigo_sem_resposta:
                amigo_sem_resposta.remove(amigo_id)

            for i, k in amigos.items():
                if i != amigo_id:
                    k[1] += 1

        case 'T': # Soma o tempo de resposta
            tempo = int(e[1])
            for amigo_id in amigos:
                amigos[amigo_id][0] += tempo

for i in amigo_sem_resposta:
    amigos[i] = -1

for i in resposta:
    print(i[0], i[1])

