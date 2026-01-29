from math import sqrt

n = int(input("Número: "))
np = False
for i in range(2, round(sqrt(n))+1):
    if n%i==0:
        np = True
        break
if np:
    print("Composite")
else:
    print("Prime")
