diametro = int(input())
h, l, p = map(int, input().split())
pi = 3.141592
r = diametro/2
vbola = 4/3 * pi * r**3
vcaixa = h * l * p

if diametro <= h and diametro <= l and diametro <= p and vbola <= vcaixa:
    print("S")
else:
    print("N")
