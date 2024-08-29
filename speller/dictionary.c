// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];


//Variables
unsigned int index;
unsigned int count_words;







// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    index = hash(word);
    node *cursor = table[index];

    while(cursor != 0)
    {
        if(strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}




// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *source =fopen(dictionary, "r");
    if(source == NULL)
    {
         return false;
    }

    char word[LENGTH + 1];
    while(fscanf(source, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
             fclose(source);
             return false;
        }

        strcpy(n->word, word);
        index = hash(word);
        n->next = table[index];
        table[index] = n;
        count_words++;
       }

    fclose(source);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(count_words != 0)
    {
        return count_words;
    }

}


// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
