import sys

def dfs(u, pi): # u é a cidade que está, origem; pi é de onde veio a cidade u
    global maxCidades
    for nv in adj[u]:
        v = nv[0]
        if v != pi: # Não quero voltar para pi, a estrada é bidirecional
            c = nv[1]
            dfs(v,u)
            if c == 0: # if going to v by means of company 0 then the longest path I can get starting in u using comp
            # O maior caminho que consigo percorrer a partir de u com a companhia 0
                maxVisitadasWithOrigin[u][0] = max(maxVisitadasWithOrigin[u][0], maxVisitadasWithOrigin[v][1]+1)
            else:
                maxVisitadasWithOrigin[u][1] = max(maxVisitadasWithOrigin[u][1], maxVisitadasWithOrigin[v][0]+1)
    maxCidades = max(maxCidades, maxVisitadasWithOrigin[u][0] + maxVisitadasWithOrigin[u][1] + 1) # O maximo total


if __name__ == "__main__":
    sys.setrecursionlimit(10**6)

    n = int(input())
    maxCidades = 0
    maxVisitadasWithOrigin = [None] * (n+1)

    adj = [None] * (n+1) # Cidades adjacentes
    for i in range(0, n+1):
        adj[i] = []
        maxVisitadasWithOrigin[i] = [0,0] # armazena o max número de cidades que posso alcançar a partir de um vértice

    for i in range(n-1):
        u, v, c = map(int, input().split())
        adj[u].append((v,c))
        adj[v].append((u,c))

    dfs(1,-1)
    print(maxCidades)
