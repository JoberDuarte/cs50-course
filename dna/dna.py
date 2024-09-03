import csv
from sys import argv, exit


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Usage: name.py name.csv name.txt")
        exit(1)

    # TODO: Read database file into a variable
    try:
        rows = []
        with open(argv[1]) as file:
            reader = csv.DictReader(file)
            for row in reader:
                rows.append(row)
    except FileNotFoundError:
        print(f"Could not open {argv[1]}")
        exit(2)


    # TODO: Read DNA sequence file into a variable
    with open(argv[2], 'r') as file_txt:
        text = file_txt.read()

    # TODO: Find longest match of each STR in DNA sequence
    save_str = []
    for i in reader.fieldnames:
        longest_match(text, i)
        save_str.append(longest_match(text, i))
    print(save_str)
    print(rows[0].keys())


    # TODO: Check database for matching profiles
    match_found = False
    for row  in rows:
        if (int(row['AGATC']) == save_str[1] and
            int(row['AATG']) == save_str[2] and
            int(row['TATC']) == save_str[3]):
            print(row["name"])
            match_found = True
            break
        elif 'TTTTTTCT' in row and
             (int(row['AGATC']) == save_str[1] and
              int(row['TTTTTTCT']) == save_str[2] and
              int(row['AATG']) == save_str[3] and
              int(row['TCTAG']) == save_str[4] and
              int(row['GATA']) == save_str[5] and
              int(row['TATC']) == save_str[6] and
              int(row['GAAA']) == save_str[7] and
              int(row['TCTG']) == save_str[8]):
             print(row["name"])
             match_found = True
             break
    if not match_found:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)



    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
