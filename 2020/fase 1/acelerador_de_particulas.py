d_emissor = 3
d_acelerador = 8

d_total = int(input())

# sensor 1: 6 ; sensor 2: 7; sensor 3: 8

def sensor(d_total):
    s1 = 6
    s2 = 7
    s3 = 8

    # Distância do emissor até o acelerador é 3
    # Se for direto para um sensor
    if d_total == s1:
        return 1
    elif d_total == s2:
        return 2
    elif d_total == s3:
        return 3

    # Se der várias voltas
    if (d_total - d_emissor) % 8 == 3:
        return 1
    elif(d_total - d_emissor) % 8 == 4:
        return 2
    elif(d_total - d_emissor) % 8 == 5:
        return 3


print(sensor(d_total))
