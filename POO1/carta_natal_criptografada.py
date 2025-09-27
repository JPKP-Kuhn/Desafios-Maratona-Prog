l = {
    '@': 'a',
    '&': 'e',
    '!': 'i',
    '*': 'o',
    '#': 'u',
}
while True:
    try:
        p = input()
        d = ''

        for c in p:
            if c in "@&!*#":
                d += l[c]
            else:
                d+=c

        print(d)

    except EOFError:
        break
