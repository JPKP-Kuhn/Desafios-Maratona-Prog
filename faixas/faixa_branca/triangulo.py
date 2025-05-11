def triangulo(a, b, c):
    # Filtra os lados
    lados = sorted([int(x) for x in [a, b, c]]) 
    a, b, c = lados

    retangulo = "S" if a**2 + b**2 == c**2 else "N"

    # Verifica o tipo de triângulo
    if a + b <= c:
        return "Invalido"
    else:
        if a == b == c:
            return f"Valido-Equilatero\nRetangulo: {retangulo}"
        elif (a == b) or (b == c):
            return f"Valido-Isoceles\nRetangulo: {retangulo}"
        else:
            return f"Valido-Escaleno\nRetangulo: {retangulo}"

entrada = input().split()
triangulo = triangulo(entrada[0], entrada[1], entrada[2])
print(triangulo)

