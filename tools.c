#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "tools.h"

//node declaration
typedef struct node
{
    char name[LENGTH_NAME];
    char number[LENGTH_NUMBER];
    struct node *next;
} node;

node *location = NULL;

const unsigned int N = 26;
node *table[N];

// Hashes word to a number
unsigned int hash(const char *name)
{
    return toupper(name[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        return false;
    }

    char *name = malloc(sizeof(char) * LENGTH_NAME);

    if (name == NULL)
    {
        return false;
    }
    char *number = malloc(sizeof(char) * LENGTH_NUMBER);

    if (number == NULL)
    {
        free(name);
        return false;
    }

    char c;
    unsigned int count_name = 0;
    unsigned int count_number = 0;

    // read data from the file
    while (fread(&c, sizeof(char), 1, file) != 0)
    {
        if (c != '\n')
        {
            if (isalpha(c) != 0)
            {
                    name[count_name] = c;
                    count_name++;
            }
            if (count_number == 0)
            {
                if (isdigit(c) != 0 || c == '+')
                {
                    number[count_number] = c;
                    count_number++;
                }
            }
            else
            {
                if(isdigit(number[count_number-1]) != 0 && c == ' ')
                {
                    number[count_number] = c;
                    count_number++;
                }
                else if (isdigit(c) != 0 )
                {
                    number[count_number] = c;
                    count_number++;
                }
            }
        }
        else
        {
            name[count_name] = '\0';
            number[count_number] = '\0';
            count_name = 0;
            count_number = 0;

            //create a new node
            node *n = malloc(sizeof(node));
            if (n == NULL )
            {
                free(name);
                free(number);
                return false;
            }

            strcpy(n->name, name);
            strcpy(n->number, number);
            n->next = NULL;

            n->next = table[hash(name)];
            table[hash(name)] = n;

        }
    }

    free(name);
    free(number);

    fclose(file);
    return true;

}

// Returns true if word is in dictionary, else false
bool check(const char *name)
{
    node *ptr = table[hash(name)];

    while (ptr != NULL)
    {
        if (strcasecmp(name, ptr->name) == 0)
        {
            location = ptr;
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

//print the number of the person
void print_number()
{
    printf("%s\n", location->number);
}

// Unloads dictionary from memory, returning true if successful
bool unload(void)
{
    node *ptr = NULL;

    for (int i = 0; i < N; i++)
    {
        ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr = next;
        }
    }

    return true;
}


