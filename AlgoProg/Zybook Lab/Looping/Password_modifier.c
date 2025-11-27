#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[50];
    scanf("%s", password);

    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] == 'i')
        {
            password[i] = '1';
        }
        else if (password[i] == 'a')
        {
            password[i] = '@';
        }
        else if (password[i] == 'm')
        {
            password[i] = 'M';
        }
        else if (password[i] == 'B')
        {
            password[i] = '8';
        }
        else if (password[i] == 's')
        {
            password[i] = '$';
        }
    }

    printf("%s!\n", password);

    return 0;
}