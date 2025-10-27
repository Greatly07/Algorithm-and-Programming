#include <stdio.h>

typedef struct
{
    char name[101];
    char NIM[10];
    int age;
    char postalCode[7];
    char placeOfBirth[101];
    char dateOfBirth[101];
    char highSchool[101];
    int numberOfSiblings;
    int height;
    char bankAccountNumber[10];
} Student;

int main()
{
    int n;
    scanf("%d", &n);

    Student database[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", database[i].name);
        scanf("%s", database[i].NIM);
        scanf("%d", &database[i].age);
        scanf("%s", database[i].postalCode);
        scanf("%s", database[i].placeOfBirth);
        scanf("%s", database[i].dateOfBirth);
        getchar();
        scanf("%[^\n]", database[i].highSchool);
        scanf("%d", &database[i].numberOfSiblings);
        scanf("%d", &database[i].height);
        scanf("%s", database[i].bankAccountNumber);
    }

    for (int t = 1; t <= n; t++)
    {
        printf("Mahasiswa ke-%d:\n", t);
        printf("Nama: %s\n", database[t].name);
        printf("NIM: %s\n", database[t].NIM);
        printf("Umur: %d\n", database[t].age);
        printf("Kode Pos: %s\n", database[t].postalCode);
        printf("Tempat Lahir: %s\n", database[t].placeOfBirth);
        printf("Tanggal Lahir: %s\n", database[t].dateOfBirth);
        printf("Almamater SMA: %s\n", database[t].highSchool);
        printf("Jumlah Saudara Kandung: %d\n", database[t].numberOfSiblings);
        printf("Tinggi Badan: %d\n", database[t].height);
        printf("NOMOR REKENING: %s\n", database[t].bankAccountNumber);
    }

    return 0;
}