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

l = letter / words * 100
s = sentences / words * 100

result = (0.0588 * l) - (0.296 * s) - 15.8


