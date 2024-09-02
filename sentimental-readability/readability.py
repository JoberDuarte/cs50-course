text = input("TEXT: ")

def count_letters(text):
    sum(1 for n in text if n.isalpha())

def count_words(text):
    len(text.split())

def count_sentences(text):
    sum(1 for n in text if n in[".", "!", "?"])

letter = count_letters(text)
word = count_words(text)
sentences = count_sentences(text)

l = float(letter) / words * 100
s = float(sentences) / words * 100

result = (0.0588 * l) - (0.296 * s) - 15.8
rounded_result = round(result)


if rounded_result < 1:
    print("Before Grade 1")
elif rounded_result >= 16:
    print("Grade 16+")
else:
    print(f"Grade {rounded_result}")

