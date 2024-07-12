#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const unsigned int LENGTH_NAME = 30;
const unsigned int LENGTH_NUMBER = 25;

//check if the name is valid
bool valid_name(char n[LENGTH_NAME])
{
    for (int i = 0; i < strlen(n); i++)
    {
        if (isalpha(n[i]) == 0 || strlen(n) > LENGTH_NAME-1 )
        {
            printf("---------------------------------------------\n");
            printf("This name is not valid! \n");
            return false;
        }
    }
    return true;
}

//check if the name is valid
bool valid_number(char n[LENGTH_NUMBER])
{
    for (int i = 0, len = strlen(n); i < len; i++)
    {
        if (isalpha(n[i]) || (ispunct(n[i]) && n[i] != '+' ) || strlen(n) > LENGTH_NUMBER-1)
        {
            printf("---------------------------------------------\n");
            printf("This number is not valid! \n");
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{

    FILE *file = fopen("phonebook.csv", "a");

    char name[LENGTH_NAME];
    char number[LENGTH_NUMBER];

    printf("-------------------------------\n");
    printf("Insert a name : ");
    scanf("%[^\n]%*c", name);
    printf("-------------------------------\n");


    while(!valid_name(name))
    {

      printf("Please insert another name : ");
      scanf("%[^\n]%*c", name);
      printf("---------------------------------------------\n");
    }

    printf("Insert the number of this contact: ");
    scanf("%[^\n]%*c", number);

    while(!valid_name(name))
    {

      printf("Please insert another number : ");
      scanf("%[^\n]%*c", number);
      printf("---------------------------------------------\n");
    }



    fprintf(file, "%s-%s\n", name, number);


    fclose(file);
}
