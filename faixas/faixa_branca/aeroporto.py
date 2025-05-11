import sys

linhas = sys.stdin.read().splitlines()
linha_atual = 0

tot_aero, tot_voos = map(int, linhas[linha_atual].split())
linha_atual += 1
teste = 0

while tot_aero != 0 and tot_voos != 0:
    teste += 1
    trafego = [0] * (tot_aero + 1)
    
    for _ in range(tot_voos):
        origem, dest = map(int, linhas[linha_atual].split())
        linha_atual += 1
        trafego[origem] += 1
        trafego[dest] += 1
    
    maior_traf = max(trafego[1:])
    aeroporto = []
    
    for i in range(len(trafego)):
        if trafego[i] == maior_traf:
            aeroporto.append(f"{i} ")

    aeroporto[-1] = aeroporto[-1].strip()
    print(f"Teste {teste}")
    for i in aeroporto:
        print(i, end='')
    print()
    
    tot_aero, tot_voos = map(int, linhas[linha_atual].split())
    linha_atual += 1
