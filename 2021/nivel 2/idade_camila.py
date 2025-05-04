# Calcular idade, Cibele < Camila < Celeste
import sys

cibele = int(input())
camila = int(input())
celeste = int(input())

idades = [cibele, camila, celeste]
idades.sort()
print(idades[1])
