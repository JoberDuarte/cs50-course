

try:
    n = int(input("Height: "))
except ValueError:
    print("Invalid input NOT INTEGER")

while n < 1 or n > 8:
    n = int(input("Height: "))

for i in range(1, n + 1):
    for k in range(n - i):
        print(" ", end="")
    for j in range(i):
        print("#", end="")
    print(end =" ")
    for p in range(i):
        print("#", end="")
    print()


