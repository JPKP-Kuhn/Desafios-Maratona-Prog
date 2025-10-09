n = int(input())
numero_tijolao = {
    2: "abc2",
    3: "def3",
    4: "ghi4",
    5: "jkl5",
    6: "mno6",
    7: "pqrs7",
    8: "tuv8",
    9: "wxyz9"
}
letra_tijolao = {
    'a': '2',
    'b': '2',
    'c': '2',
    'd': '3',
    'e': '3',
    'f': '3',
    'g': '4',
    'h': '4',
    'i': '4',
    'j': '5',
    'k': '5',
    'l': '5',
    'm': '6',
    'n': '6',
    'o': '6',
    'p': '7',
    'q': '7',
    'r': '7',
    's': '7',
    't': '8',
    'u': '8',
    'v': '8',
    'w': '9',
    'x': '9',
    'y': '9',
    'z': '9',
}

def ultimo_digito(s):
    for i in reversed(s):
        if i.isdigit():
            return i
    return None

for _ in range(n):
    p = input()

    s = ""
    if p[0].isupper():
        s+='#'
    if p[0] == ' ':
        s+='0'
    letram = p[0].lower()
    num = letra_tijolao[letram]
    vezes = numero_tijolao[int(num)].index(letram)+1
    s+= num * vezes

    for i in range(1, len(p)):
        c = p[i]
        maiusculo = False
        if c == ' ':
            s+='0'
        else:
            letram = c.lower()
            num = letra_tijolao[letram]
            vezes_press = numero_tijolao[int(num)].index(letram)+1

            if c.isupper():
                s+='#'
                maiusculo = True

            anterior = ultimo_digito(s)
            if num == anterior and not maiusculo:
                s+='*'

            s += num * vezes_press


    print(s)

