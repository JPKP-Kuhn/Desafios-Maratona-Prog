# Números em Braille
# Preenche a matriz com os números em braille, primeiro indice de braille ocupe a primeira linha, o segundo índice ocupe a segunda linha e o terceiro índice ocupe a terceira linha

def converter_para_braille(numero):
    global matriz
    n1 = ["*.", "..", ".."]
    n2 = ["*.", "*.", ".."]
    n3 = ["**", "..", ".."]
    n4 = ["**", ".*", ".."]
    n5 = ["*.", ".*", ".."]
    n6 = ["**", "*.", ".."]
    n7 = ["**", "**", ".."]
    n8 = ["*.", "**", ".."]
    n9 = [".*", "*.", ".."]
    n0 = [".*", "**", ".."]

    dicionario_braille = {
        "1": n1,
        "2": n2,
        "3": n3,
        "4": n4,
        "5": n5,
        "6": n6,
        "7": n7,
        "8": n8,
        "9": n9,
        "0": n0
    }
    
    for i in range(3):
        matriz[i].append(dicionario_braille[numero][i])  # Adiciona o valor correspondente à lista correta

def converter_para_numero(matriz):
    dicionario_braille = {
        "*. .. ..": "1",
        "*. *. ..": "2",
        "** .. ..": "3",
        "** .* ..": "4",
        "*. .* ..": "5",
        "** *. ..": "6",
        "** ** ..": "7",
        "*. ** ..": "8",
        ".* *. ..": "9",
        ".* ** ..": "0"
    }
    
    resultado = ""
    
    # Itera sobre as colunas da matriz (cada coluna representa um número em Braille)
    for col in range(len(matriz[0])):
        # Combina as 3 linhas da matriz para formar a representação Braille de uma coluna
        braille = f"{matriz[0][col]} {matriz[1][col]} {matriz[2][col]}"
        
        # Converte a representação Braille para o número correspondente
        resultado += dicionario_braille[braille]
    
    return resultado

d = int(input())
while d > 0:
    matriz = [[] for _ in range(3)]  # Inicializa a matriz com 3 listas vazias
    opcao = input()

    if opcao == 'S':  # Entrada será número para Braille
        numeros = input()
        for i in numeros:
            converter_para_braille(i)

        # Exibe a matriz na posição de braille
        for i in range(3):
            print(" ".join(matriz[i]))
    
    elif opcao == 'B':  # Entrada será Braille para número
        for i in range(3):
            matriz[i] = input().split()
        # Converte a matriz de Braille para números
        print(converter_para_numero(matriz))

    d = int(input())
