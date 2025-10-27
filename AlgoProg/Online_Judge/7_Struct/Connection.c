#include <stdio.h>
#include <string.h>

typedef struct
{
    char id[31];
    char name[31];
    char gender[10];
    char fatherName[31];
    char motherName[31];
    int siblings;
} Student;

typedef struct
{
    char id[31];
    char name[31];
    char gender[10];
    int numOfStudents;

    Student studentData[101];
} Lecturer;

int main()
{
    int n;
    scanf("%d", &n);

    Lecturer database[101];
    for (int t = 1; t <= n; t++)
    {
        scanf("%s", database[t].id);
        scanf("%s", database[t].name);
        scanf("%s", database[t].gender);
        scanf("%d", &database[t].numOfStudents);

        for (int i = 1; i <= database[t].numOfStudents; i++)
        {
            scanf("%s", database[t].studentData[i].id);
            scanf("%s", database[t].studentData[i].name);
            scanf("%s", database[t].studentData[i].gender);
            scanf("%s", database[t].studentData[i].fatherName);
            scanf("%s", database[t].studentData[i].motherName);
            scanf("%d", &database[t].studentData[i].siblings);
        }
    }

    int k;
    scanf("%d", &k);

    printf("Kode Dosen: %s\n", database[k].id);
    printf("Nama Dosen: %s\n", database[k].name);
    printf("Gender Dosen: %s\n", database[k].gender);
    printf("Jumlah Mahasiswa: %d\n", database[k].numOfStudents);

    for (int i = 1; i <= database[k].numOfStudents; i++)
    {
        printf("Kode Mahasiswa: %s\n", database[k].studentData[i].id);
        printf("Nama Mahasiswa: %s\n", database[k].studentData[i].name);
        printf("Gender Mahasiswa: %s\n", database[k].studentData[i].gender);
        printf("Nama Ayah: %s\n", database[k].studentData[i].fatherName);
        printf("Nama Ibu: %s\n", database[k].studentData[i].motherName);
        printf("Jumlah Saudara Kandung: %d\n", database[k].studentData[i].siblings);
    }

    return 0;
}