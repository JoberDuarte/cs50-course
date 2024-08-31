def get_height()
    while True:
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                break
            else:
                print("Please Enter an integer from 1 to 8")
        except ValueError:
            print("Invalid input NOT INTEGER")


def print_pyramid()
    for i in range(1, n + 1):
        for k in range(n - i):
            print(" ", end="")
        for j in range(i):
            print("#", end="")
        print(end =" ")
        for p in range(i):
            print("#", end="")
        print()


