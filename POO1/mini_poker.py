def sequencia(mao) -> int:
    l = sorted(mao)
    for i in range(len(l)-1):
        if l[i+1]-l[i] != 1:
            return 0
    return l[0]+200

def count_freq(mao) -> dict:
    d = dict()
    for i in mao:
        d[i] = d.get(i,0)+1
    return d


def quadra(mao) -> int:
    l = set(mao)
    if len(l) == 2:
        d = count_freq(mao)
        maior=0
        mk=0
        for k, v in d.items():
            if v == 1 or v == 4:
                if v>maior:
                    maior=v
                    mk=k
            else:
                return 0
        return mk+180
    else:
        return 0

def trinca_par(mao) -> int:
    l = set(mao)
    if len(l) == 2:
        d = count_freq(mao)
        maior=0
        mk=0
        for k, v in d.items():
            if v == 2 or v == 3:
                if v>maior:
                    maior=v
                    mk=k
            else:
                return 0
        return mk+160
    else:
        return 0

def trinca(mao) -> int:
    l = set(mao)
    if len(l) == 3:
        d = count_freq(mao)
        maior=0
        mk=0
        for k, v in d.items():
            if v == 3 or v == 1:
                if v>maior:
                    maior=v
                    mk=k
            else:
                return 0
        return mk+140
    else:
        return 0

def duas_duplas(mao) -> int:
    l = set(mao)
    if len(l) == 3:
        d = count_freq(mao)
        mx, my =0, 100
        for k, v in d.items():
            if v == 1 or v == 2:
                if v ==2:
                    mx = max(mx, k)
                    my = min(my, k)
            else:
                return 0
        return 3*mx+2*my+20
    else:
        return 0

def dupla(mao):
    l = set(mao)
    if len(l) == 4:
        d = count_freq(mao)
        for k, v in d.items():
            if v ==1 or v==2:
                if v==2:
                    return k
            else:
                return 0
    else:
        return 0

n = int(input())
for _ in range(n):
    mao = list(map(int, input().split()))
    pontuacao=0
    pontuacao+=sequencia(mao)
    pontuacao+=quadra(mao)
    pontuacao+=trinca_par(mao)
    pontuacao+=trinca(mao)
    pontuacao+=duas_duplas(mao)
    pontuacao+=dupla(mao)

    print("Teste", _+1)
    print(pontuacao)
    print()

