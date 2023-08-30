#include <stdio.h>
#include <string.h>

void removeSpaces(char *str)
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

void main () {
    char kalimat1[100], kalimat2[100], kalimat3[100], gabungan[100];
    printf("==============================\n");
    printf("            Group 6           \n");
    printf("==============================\n");
    printf("======= Program Input ========\n");
    printf("==============================\n");

    printf("input kalimat 1: ");
    gets(kalimat1);
    printf("input kalimat 2: ");
    gets(kalimat2);
    printf("input kalimat 3: ");
    gets(kalimat3);

    strcpy(gabungan, kalimat1);
    strcat(gabungan, " ");
    strcat(gabungan, kalimat2);
    strcat(gabungan, " ");
    strcat(gabungan, kalimat3);

    printf("==============================\n");
    printf("Gabungan 3 buah kalimat = %s \n", gabungan);
    
    printf("Hasil pembalikan kalimat = %s \n", strrev(gabungan));

    removeSpaces(kalimat1);
    removeSpaces(kalimat2);
    removeSpaces(kalimat3);
    printf("==============================\n");
    printf("jumlah huruf kalimat 1 = %d \n", strlen(kalimat1));
    printf("jumlah huruf kalimat 2 = %d \n", strlen(kalimat2));
    printf("jumlah huruf kalimat 3 = %d \n", strlen(kalimat3));
    printf("==============================\n");
    printf("Total jumlah huruf     = %d \n", strlen(kalimat1) + strlen(kalimat2) + strlen(kalimat3));
    printf("==============================\n");
}