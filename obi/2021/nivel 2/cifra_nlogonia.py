# Criptografar uma palavra
p = input()

def cifra_nlogonia(palavra):
    alfabeto = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'x', 'z']
    vogais = ['a', 'e', 'i', 'o', 'u']
    consoante = [letra for letra in alfabeto if letra not in vogais]

    def vogal_proxima(letra):
        pos_letra = alfabeto.index(letra)
        vogal_perto = ''
        menor_distancia = float('inf')

        for vogal in vogais:
            pos_vogal = alfabeto.index(vogal)
            distancia = abs(pos_letra - pos_vogal)

            if distancia < menor_distancia or (distancia == menor_distancia and pos_vogal < alfabeto.index(vogal_perto)):
                menor_distancia = distancia
                vogal_perto = vogal

        proxima_consoante = ''
        if letra == 'z':
            proxima_consoante = 'z'
        else:
            proxima_consoante = consoante[consoante.index(letra)+1]

        return letra + vogal_perto + proxima_consoante

    palavra_final = ""
    for i in palavra:
        if i not in vogais:
            palavra_final += vogal_proxima(i)
        else:
            palavra_final += i

    return palavra_final


print(cifra_nlogonia(p))

