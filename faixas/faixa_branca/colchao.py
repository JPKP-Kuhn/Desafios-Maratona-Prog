colchao = sorted([int(x) for x in input().split()])
porta = sorted([int(x) for x in input().split()])

if colchao[0] <= porta[0] and colchao[1] <= porta[1]:
    print('S')
else:
    print('N')

