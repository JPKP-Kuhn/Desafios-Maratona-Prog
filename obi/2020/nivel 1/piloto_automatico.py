# Decidir se uma carro B que está no meio de um A e de um C precisa acelerar, freiar ou manter
a = int(input())
b = int(input())
c = int(input())

if b-a < c-b:
    print(1)
elif b-a > c-b:
    print(-1)
else:
    print(0)
