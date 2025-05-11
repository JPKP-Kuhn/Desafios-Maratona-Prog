import math

entrada = int(input())

def ver_primo(x):
    if x == 1:
        return "Not Prime"
    else:
        raiz = int(x**0.5)
        for i in range(2, raiz+1):
            if x % i == 0:
                return "Not Prime"
    return "Prime"

while entrada > 0:
    x = int(input())

    print(ver_primo(x))

    entrada -= 1


