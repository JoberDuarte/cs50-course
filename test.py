
n = int(input("Height: "))

while n < 1 or n > 8:
    n = int(input("Height: "))


for i in range(n):
    for k in range(n - i):
        print(" ", end="")
    for j in range(i):
        print("#", end="")
    print()

