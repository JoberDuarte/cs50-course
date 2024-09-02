from itertools import tee, islice

card_number = input("Number: ")

def split_list(card_number):
    it_1, it_2 = tee(card_number)
    return list(map(int, islice(it_1, 0, None, 2))), list(map(int, islice(it_2, 1, None, 2)))


def multiply_list(multiply_list):
    # multiply the list
    for i in range(len(multiply_list)):
        multiply_list[i] = multiply_list[i] * 2

    #separates each digit from the list
    separeted_digits = []
    for number in multiply_list:
        number_str = str(number)

        separeted_digits.extend(int(digit) for digit in number_str)

    return separeted_digits

def credit_card(number):
    if len(number) == 15 and number[0] == 3  and number[1] == 4 or 7
        print("AMEX")
    elif len(number) == 15 and number[0] == 5 and number[1] == 1 or 2 or 3 or 4 or 5


list_1, list_2 = split_list(card_number)


if len(card_number) % 2 == 0:
   separeted_digits = multiply_list(list_1)
   sum_list_1 = sum(separeted_digits)
   sum_list_2 = sum(list_2)
   total = sum_list_1 + sum_list_2

   if total % 10 == 0:
       print("Valid Card")
   else:
       print("Invalid Card")


elif len(card_number) % 2 != 0:
    separeted_digits = multiply_list(list_2)
    sum_list_2 = sum(separeted_digits)
    sum_list_1 = sum(list_1)
    total = sum_list_1 + sum_list_2
    print(total)

    if total % 10 == 0:
       print("Valid Card")
    else:
       print("Invalid Card")





