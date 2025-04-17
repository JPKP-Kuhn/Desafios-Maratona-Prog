premiados = int(input())

tamanhos = input().split()

n_peq = int(input())
n_med = int(input())

p = 0
m = 0

for i in tamanhos:
    if int(i) == 1:
        p += 1
    else:
        m += 1


if p == n_peq and m == n_med:
    print('S')
else:
    print('N')
