n, m = map(int, input().split())
fechadura = list(map(int, input().split()))
movimentos=0
for i in range(len(fechadura)-1):
    if fechadura[i] == m:
        continue
    dif = abs(m - fechadura[i])
    movimentos+=dif
    fechadura[i] = m 
    if (fechadura[i+1] > m):
        fechadura[i+1]-=dif
    else:
        fechadura[i+1]+=dif

print(movimentos)
