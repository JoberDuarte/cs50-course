
n = int(input("Height: "))

while n < 1 or n > 8:
    n = int(input("Height: "))

for i in range(1, n + 1):
    for k in range(n - i):
        print(" ", end="")
    for j in range(i):
        print("#", end="")
    print()
    for p in range(i):
        print("#", end="")
    print()


