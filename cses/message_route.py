n, m = map(int, input().split())

adj = [[] for _ in range(n)]

for i in range(m):
    v, e = map(int, input().split())
    adj[v-1].append(e)
    adj[e-1].append(v)
"""
print(adj)
for i in range(len(adj)):
    print(f"Vértice {i+1}, arestas: ", end='')
    for j in range(len(adj[i])):
        print(adj[i][j], end=' ')
    print()
"""
# Algorítimo BFS para verificar a distância mínima
fila = []
averificar = [False for _ in range(n)]
pai = [-1 for _ in range(n)]
dist = [0 for _ in range(n)]

# Vou verificar do primeiro ao último
pc = 0
averificar[pc] = True
fila.append(pc)

while len(fila) > 0:
    u = fila.pop(0)

    if u == n-1:
        break

    for i in adj[u]:
        if not averificar[i-1]:
            averificar[i-1] = True
            dist[i-1] = dist[u] + 1 
            pai[i-1] = u 
            fila.append(i-1)

#print(f"Distâncias: {dist}")
#print(f"Pais: {pai}")
# Caminho reverso para ter os computadores
if averificar[n-1]:
    caminho = []
    a = n-1
    while a != -1:
        caminho.append(a+1)
        a = pai[a]

    print(len(caminho))
    caminho.reverse()
    for i in caminho:
        print(i, end=' ')
    print()

else:
    print("IMPOSSIBLE")


