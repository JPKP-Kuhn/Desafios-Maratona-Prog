escolha = list(map(int, input().split()))
sorteio = list(map(int, input().split()))

c = 0
for i in escolha:
    if i in sorteio:
        c+=1
if c<3:
    print('azar')
elif c==3:
    print('terno')
elif c==4:
    print('quadra')
elif c==5:
    print('quina')
else:
    print('sena')


