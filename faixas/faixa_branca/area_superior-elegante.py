# Código mais elegante e escalável, mas em questão de maratona, esse é meio difícil de depurar e também pensá-lo sob pressão

def main():
    # Inicializa matriz 12x12
    mat = [[0 for _ in range(12)] for _ in range(12)]
    
    # Lê a operação desejada (S para soma, M para média)
    o = input()
    
    # Lê os valores da matriz
    for i in range(12):
        for j in range(12):
            mat[i][j] = float(input())
    
    # Calcula a soma ou média
    resultado = calcular_area_superior(mat, o)
    
    # Imprime o resultado formatado
    print(f"{resultado:.1f}")

def calcular_area_superior(mat, operacao):
    soma = 0
    count = 0
    
    # Percorre apenas a área superior da matriz
    for i in range(5):  # Linhas 0 até 4
        # Define os limites de colunas para cada linha
        inicio_coluna = i + 1
        fim_coluna = 12 - i - 1
        
        for j in range(inicio_coluna, fim_coluna):
            soma += mat[i][j]
            count += 1
    
    # Retorna soma ou média conforme solicitado
    if operacao == 'S':
        return soma
    else:  # operacao == 'M'
        return soma / count

if __name__ == "__main__":
    main()

