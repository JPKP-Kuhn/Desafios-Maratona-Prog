a, b, c = map(int, input().split())
h, l = map(int, input().split())

n = [a, b, c]
n.sort()

if ((n[0] <= h and n[1] <= l) or (n[0] <= h and n[2] <= l) or (n[1] <= h and n[2] <= l) or (n[1] <= l and n[2] <= h) or (n[0] <= l and n[1] <= h)):
    print("S")
else:
    print("N")

