
n = int(input("Height: "))

while n < 1 or n > 8:
    n = int(input("Height: "))


for i in range(n):
    print()
    for j in range(i):
        print(" ", end="")
    for k in range(i):
        print("#", end="")

