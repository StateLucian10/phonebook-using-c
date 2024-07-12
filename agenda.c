#include <stdio.h>
#include <stdbool.h>
#include "tools.h"

int main()
{
    char name[LENGTH_NAME];
    char *phonebook = "phonebook.csv";
    bool loaded = load(phonebook);

    printf("----------------------------------\n");
    printf("Please insert a name : ");
    scanf("%[^\n]%*c", name);
    printf("----------------------------------\n");

    if(!loaded)
    {
        printf("Could not load %s.\n", phonebook);
        return 1;
    }

    if (check(name) == true)
    {
        printf("------------------------------------------\n");
        printf("The number of the person is : ");
        print_number();
        printf("------------------------------------------\n");
    }
    else
    {
        printf("------------------------\n");
        printf("Can't find this person.\n");
        printf("------------------------\n");
    }
}


