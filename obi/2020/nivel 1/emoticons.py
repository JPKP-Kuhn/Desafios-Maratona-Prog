msg = input().strip()
feliz = triste = 0

for i in range(0, len(msg)-2):
    if msg[i] == ":" and msg[i+1] == "-":
        if msg[i+2] == ")":
            feliz += 1
        elif msg[i+2] == "(":
            triste += 1

if feliz > triste:
    print("divertido")
elif triste > feliz:
    print("chateado")
else:
    print("neutro")
