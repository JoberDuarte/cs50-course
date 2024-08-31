def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                break
            else:
                print("Please Enter an integer from 1 to 8")
        except ValueError:
            print("Invalid input NOT INTEGER")


def print_pyramid(height):
    for i in range(1, height + 1):
        print(" " * (height - 1) + "#" * i, end=" ")
        print("#" * i)

height = get_height()
print_pyramid(height)


