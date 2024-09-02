text = input("TEXT: ")

def count_letters(text):
    letters = sum(1 for n in text if n.isalpha())
    print(f"{letters}")

count_letters(text)

words = len(text.split())

print(f"{words}")



