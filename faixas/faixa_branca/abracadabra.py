while True:
    try:
        palavra = input()
        
        for i in range(len(palavra)):
            # Espaços iniciais para formar o triângulo
            print(' ' * i, end='')
            
            # Imprime cada letra com espaço entre elas, exceto a última
            for j in range(len(palavra) - i):
                if j < len(palavra) - i - 1:
                    print(palavra[j] + ' ', end='')
                else:
                    print(palavra[j], end='')
            
            print()  # Nova linha após cada linha do triângulo
        
        print()  # Linha em branco após cada caso de teste
        
    except EOFError:
        break
