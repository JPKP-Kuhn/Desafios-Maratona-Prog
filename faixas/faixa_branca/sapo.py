pedras, sapos = map(int, input().split())

pos = [0] * pedras

for _ in range(sapos):
    sapoi, pulos = map(int, input().split()) 
    pos[sapoi - 1] = 1
    for i in range(sapoi-1, len(pos), pulos):
        pos[i] = 1
    for j in range(sapoi-1, -1, -pulos):
        pos[j] = 1

print(pos)
