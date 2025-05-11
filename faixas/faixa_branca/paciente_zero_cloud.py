# Determinar quem foi o primeiro paciente da infecção
tot_infect, tot_cadeias = map(int, input().split())

# Lista para rastrear todas as pessoas que foram infectadas por alguém
pessoas_infectadas = set()

# Lista para rastrear todas as fontes de infecção nas cadeias
todas_fontes = set()

# Processa cada cadeia de infecção
for _ in range(tot_cadeias):
    cadeia = list(map(int, input().split()))
    fonte = cadeia[0]  # A pessoa que infectou os outros
    num_infectados = cadeia[1]  # Número de pessoas infectadas pela fonte
    infectados = cadeia[2:2+num_infectados]  # Lista das pessoas infectadas
    
    # Adiciona a fonte ao conjunto de todas as fontes
    todas_fontes.add(fonte)
    
    # Adiciona todos os infectados ao conjunto de pessoas infectadas
    for infectado in infectados:
        pessoas_infectadas.add(infectado)

# Os pacientes zero são aqueles que não foram infectados por ninguém
# Ou seja, não estão no conjunto de pessoas infectadas
pacientes_zero = []

# Verifica todos os números de 1 até o total de infectados
for i in range(1, tot_infect + 1):
    if i not in pessoas_infectadas:
        pacientes_zero.append(i)

# Imprime os pacientes zero em ordem crescente
for paciente in sorted(pacientes_zero):
    print(paciente)

