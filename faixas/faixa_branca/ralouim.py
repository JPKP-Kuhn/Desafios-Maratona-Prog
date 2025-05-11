def solucao_ralouim():
    # Leitura da entrada
    n = int(input())
    tendas = []
    for _ in range(n):
        x, y = map(int, input().split())
        tendas.append((x, y))
    
    # Adicionar o palácio como ponto inicial (0,0)
    pontos = [(0, 0)] + tendas
    
    # Calcular distâncias entre todos os pontos
    distancias = []
    for i, (xi, yi) in enumerate(pontos):
        linha = []
        for j, (xj, yj) in enumerate(pontos):
            dist = ((xi - xj) ** 2 + (yi - yj) ** 2) ** 0.5
            linha.append(dist)
        distancias.append(linha)
    
    # Memoização
    # memo[pos][ultima][dist_min] = máximo de guloseimas
    # pos = tenda atual (0 = palácio)
    # ultima = última tenda visitada (-1 = nenhuma)
    # dist_min = mínima distância permitida para a próxima visita
    memo = {}
    
    def dp(pos, ultima, dist_min):
        if (pos, ultima, dist_min) in memo:
            return memo[(pos, ultima, dist_min)]
        
        melhor = 0
        
        # Tentar visitar cada tenda
        for prox in range(1, n+1):  # começando de 1 pois 0 é o palácio
            # Não podemos visitar consecutivamente a mesma tenda
            if prox == ultima:
                continue
                
            dist = distancias[pos][prox]
            
            # A distância precisa ser menor que a distância mínima permitida
            if dist < dist_min:
                # Ganhar uma guloseima + o melhor que podemos fazer a partir daqui
                resultado = 1 + dp(prox, prox, dist)
                melhor = max(melhor, resultado)
        
        memo[(pos, ultima, dist_min)] = melhor
        return melhor
    
    # Começamos no palácio (pos=0), sem ter visitado nenhuma tenda (ultima=-1),
    # e com uma distância mínima permitida "infinita" (podemos ir para qualquer lugar)
    return dp(0, -1, float('inf'))


print(solucao_ralouim())
