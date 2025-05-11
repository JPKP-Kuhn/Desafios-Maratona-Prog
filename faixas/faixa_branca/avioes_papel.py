def divisao(competidores, papel, pap_comp):
    return 'S' if competidores * pap_comp <= papel else 'N'

entrada = input().split()
competidores = int(entrada[0])
papel = int(entrada[1])
pap_comp = int(entrada[2])
print(divisao(competidores, papel, pap_comp))
