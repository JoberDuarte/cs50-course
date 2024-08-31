def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if 1 <= n <= 8:
                return n
            else:
                print("Please enter an integer from 1 to 8.")
        except ValueError:
            print("Invalid input. Please enter an integer.")

def print_pyramid(height):
    for i in range(1, height + 1):
        # Print spaces and hashes for the left side
        print(" " * (height - i) + "#" * i, end="  ")
        # Print hashes for the right side
        print("#" * i)

height = get_height()
print_pyramid(height)
