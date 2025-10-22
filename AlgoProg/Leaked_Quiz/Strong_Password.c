#include <stdio.h>
#include <string.h>

int main()
{
    int passwordStrength = 0;
    char *specialCharacters = "!@#$%^&*()-+";

    char password[101];
    scanf("%s", password);
    int passLen = strlen(password);

    // check panjang password
    if (passLen < 8 || passLen > 33)
    {
        printf("invalid password\n");
        return 0;
    }

    // utk digit
    for (int i = 0; i < passLen; i++)
    {
        if (password[i] >= '0' && password[i] <= '9')
        {
            passwordStrength += 1;
            break;
        }
    }

    // utk uppercase
    for (int i = 0; i < passLen; i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            passwordStrength += 1;
            break;
        }
    }

    // utk special characters
    for (int i = 0; i < passLen; i++)
    {
        if (strchr(specialCharacters, password[i]) != NULL)
        {
            passwordStrength += 1;
            break;
        }
    }

    if (passwordStrength == 3)
    {
        printf("strong password\n");
    }
    else if (passwordStrength == 2)
    {
        printf("medium password\n");
    }
    else
    {
        printf("weak password\n");
    }

    return 0;
}