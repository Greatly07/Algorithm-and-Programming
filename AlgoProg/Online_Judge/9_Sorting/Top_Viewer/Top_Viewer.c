#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[1001];
    char artist[1001];
    int views;
} BeeTube;

BeeTube database[100];

void bSort(int j)
{
    char tempTitle[1001];
    strcpy(tempTitle, database[j].title);
    char tempArtist[1001];
    strcpy(tempArtist, database[j].artist);
    int tempViews = database[j].views;

    strcpy(database[j].title, database[j + 1].title);
    strcpy(database[j].artist, database[j + 1].artist);
    database[j].views = database[j + 1].views;

    strcpy(database[j + 1].title, tempTitle);
    strcpy(database[j + 1].artist, tempArtist);
    database[j + 1].views = tempViews;
}

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        printf("there is no file found");
        return 0;
    }

    int counter = 0;
    int i = 0;
    while (fscanf(fp, " %[^#]#%[^#]#%d", database[i].title, database[i].artist, &database[i].views) == 3)
    {
        i++;
        counter++;
    }

    // Bubble Sort
    for (int i = 0; i < counter - 1; i++)
    {
        for (int j = 0; j < counter - 1 - i; j++)
        {
            if (database[j].views < database[j + 1].views)
            {
                bSort(j);
            }
            else if (database[j].views == database[j + 1].views)
            {
                if (strcmp(database[j].title, database[j + 1].title) > 0)
                {
                    bSort(j);
                }
            }
        }
    }

    for (int i = 0; i < counter; i++)
    {
        printf("%s by %s - %d\n", database[i].title, database[i].artist, database[i].views);
    }

    fclose(fp);

    return 0;
}