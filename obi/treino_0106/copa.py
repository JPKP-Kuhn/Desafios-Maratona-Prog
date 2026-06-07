k = int(input())
l = int(input())


maior = max(l, k)
menor = min(l, k)

if (maior%2==0 and menor+1 == maior):
    print("oitavas")
elif (maior >= 9 and menor <= 8):
    print("final")
elif (maior <= 8 and menor <= 8) or (maior >= 9 and menor >= 9):
    if (menor <= 4 and maior <= 4) or (menor >= 5 and menor <= 8 and maior >= 5 and maior <= 8) or (menor >= 9 and menor <= 12 and maior >= 9 and maior <= 12) or (menor >= 13 and menor <= 16 and maior >= 13 and maior <= 16):
        print("quartas")
    else:
        print("semifinal")
