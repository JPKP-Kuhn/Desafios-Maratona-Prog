def dfs(mat, i, j, n, m):
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    mat[i] = mat[i][:j] + '#' + mat[i][j+1:]  # Marca a célula como visitada
    
    for d in range(4):
        nx = dx[d] + i
        ny = dy[d] + j
        # Verificando se as coordenadas estão dentro dos limites
        if 0 <= nx < n and 0 <= ny < m:
            if mat[nx][ny] == '.':
                dfs(mat, nx, ny, n, m)

def main():
    n, m = map(int, input().split())
    rooms = 0
    
    mat = []
    for i in range(n):
        mat.append(input())
    
    for i in range(n):
        for j in range(m):  
            if mat[i][j] == '.':
                dfs(mat, i, j, n, m)
                rooms += 1
    
    print(rooms)

if __name__ == "__main__":
    import sys
    sys.setrecursionlimit(10**9)
    main()
