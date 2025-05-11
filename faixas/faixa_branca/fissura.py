from collections import deque

def simular_erupcao(mapa, forca):
    n = len(mapa)
    # Cria uma cópia do mapa para modificação
    resultado = [list(linha) for linha in mapa]
    
    # Marca posições já visitadas para evitar processamento repetido
    visitado = [[False for _ in range(n)] for _ in range(n)]
    
    # Fila para BFS
    fila = deque()
    
    # Verificar a posição inicial (0,0)
    if int(mapa[0][0]) <= forca:
        fila.append((0, 0))
        resultado[0][0] = '*'
        visitado[0][0] = True
    
    # Direções: direita, esquerda, abaixo, acima
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    # BFS para propagar a lava
    while fila:
        x, y = fila.popleft()
        
        # Verificar as 4 direções adjacentes
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            
            # Verificar se a nova posição está dentro dos limites do mapa
            if 0 <= nx < n and 0 <= ny < n:
                # Verificar se a posição não foi visitada e a altitude permite a lava avançar
                if not visitado[nx][ny] and int(mapa[nx][ny]) <= forca:
                    visitado[nx][ny] = True
                    resultado[nx][ny] = '*'
                    fila.append((nx, ny))
    
    # Converter resultado de volta para strings
    return [''.join(linha) for linha in resultado]

def main():
    # Leitura da entrada
    n, f = map(int, input().split())
    
    mapa = []
    for _ in range(n):
        mapa.append(input())
    
    # Simular o avanço da lava
    resultado = simular_erupcao(mapa, f)
    
    # Imprimir o resultado
    for linha in resultado:
        print(linha)

if __name__ == "__main__":
    main()
