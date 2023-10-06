#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

double strtodoub(const char *string)
{
    // Check if the string is empty.
    if (!string || !*string)
    {
        return 0.0;
    }

    // Check if the string contains any whitespace characters.
    for (int i = 0; i < strlen(string); i++)
    {
        if (isspace(string[i]))
        {
            return 0.0;
        }
    }

    // Check if the string contains any characters other than numbers and decimal points.
    for (int i = 0; i < strlen(string); i++)
    {
        if (!isdigit(string[i]) && string[i] != '.')
        {
            return 0.0;
        }
    }

    // Try to convert the string to a double.
    double double_value;
    if (sscanf(string, "%lf", &double_value) != 1)
    {
        return 0.0;
    }

    // Return the double value.
    return double_value;
}

int strtoint(char *string)
{
    // Check if the string is empty.
    if (!string || !*string)
    {
        return 0;
    }

    // Check if the string contains any whitespace characters.
    for (int i = 0; i < strlen(string); i++)
    {
        if (isspace(string[i]))
        {
            return 0;
        }
    }

    // Check if the string contains any characters other than numbers.
    for (int i = 0; i < strlen(string); i++)
    {
        if (!isdigit(string[i]))
        {
            return 0;
        }
    }

    // Try to convert the string to an int.
    int int_value;
    if (sscanf(string, "%d", &int_value) != 1)
    {
        return 0;
    }

    // Return the int value.
    return int_value;
}

bool continueOrNo(bool *lanjut)
{
    char input;
    printf("Apakah ingin lanjut input? (y/n): \n");
    scanf(" %c", &input); // Perhatikan spasi sebelum %c untuk menghindari karakter newline

    if (input == 'y' || input == 'Y')
    {
        *lanjut = true;
    }
    else
    {
        *lanjut = false;
    }
}

int main()
{
    int jumlahCoupon;
    char input[255];
    // bool isValid;
    bool lanjut = true;

    printf("==============================\n");
    printf("            Group 6           \n");
    printf("==============================\n");
    printf("  Program supermarket week 7  \n");
    printf("==============================\n");

    do
    {
            int* jumlahTransaksi;
            printf("%d", jumlahTransaksi);

            printf("Masukkan total pembelian: ");
            fgets(input, sizeof(input), stdin);

            // Remove the newline character from the end of the string.
            input[strlen(input) - 1] = '\0';

            jumlahTransaksi = strtoint(input);

            continueOrNo(&lanjut);

    } while (lanjut);

    // do
    // {
    //     bool isValid = true;

    //     printf("Masukkan total pembelian: ");
    //     fgets(input, sizeof(input), stdin);

    //     // Remove the newline character from the end of the string.
    //     input[strlen(input) - 1] = '\0';

    //     jumlahTransaksi = strtodoub(input);

    //     if (isValid == false)
    //     {
    //         printf("Tidak valid\n");
    //         continueOrNo(&lanjut, &is);
    //     }

    //     // jumlahTransaksi = strtodoub(input);

    // } while (lanjut);

    // while (lanjut) {
    //     printf("Masukkan total pembelian: ");
    //     fgets(input, sizeof(input), stdin);

    //     // Remove the newline character from the end of the string.
    //     input[strlen(input) - 1] = '\0';

    //     jumlahTransaksi = strtodoub(input);

    //     if (jumlahTransaksi == 0) {
    //         printf("Tidak valid");

    //         continueOrNo(&lanjut);
    //     }
    // }

    return 0;
}