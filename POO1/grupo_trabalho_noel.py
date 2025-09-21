n = int(input())
total=0
bonecos, arquitetos, musicos, desenhistas = 0,0,0,0
for i in range(n):
    e = input().split()
    h = int(e[2])
    if (e[1] == "bonecos"):
        bonecos+=h
    elif (e[1] == "arquitetos"):
        arquitetos+=h
    elif (e[1] == "musicos"):
        musicos+=h
    elif (e[1] == "desenhistas"):
        desenhistas+=h

total=0
total+=bonecos//8
total+=arquitetos//4
total+=musicos//6
total+=desenhistas//12

print(total)

