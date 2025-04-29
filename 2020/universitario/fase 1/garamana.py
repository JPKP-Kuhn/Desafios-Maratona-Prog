# Detectar anagrams
import unicodedata

p = input().lower()
a = input().lower()

def remover_acentos(palavra):
    texto = unicodedata.normalize('NFD', palavra)
    return ''.join(c for c in texto if not unicodedata.category(c).startswith('M'))
p = remover_acentos(p)
a = remover_acentos(a)

def contar_letras(palavra):
    contagem = {}
    for l in palavra:
        if l in contagem:
            contagem[l] += 1
        else:
            contagem[l] = 1
    return contagem


def anagrama_coringa(letras1, letras2):
    aster = letras2['*']
    dif = 0
    for i in letras1:
        if i not in letras2:
            dif += 1
    return True if aster == dif else False


if contar_letras(p) == contar_letras(a):
    print('S')
else:
    if '*' in a and anagrama_coringa(contar_letras(p), contar_letras(a)):
        print('S')
    else:
        print('N')
