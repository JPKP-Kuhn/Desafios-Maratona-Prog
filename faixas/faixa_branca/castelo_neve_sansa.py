n, k = map(int, input().split()) # Número de torres, número total de picos
alturas = list(map(int, input().split()))

picos = 0
for i in range(1, len(alturas)-1):
    if alturas[i] > alturas[i-1] and alturas[i] > alturas[i+1]:
        picos+=1

if picos == k:
    print("beautiful")
else:
    print("ugly")

