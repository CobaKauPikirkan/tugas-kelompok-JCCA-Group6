#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void clearScreen()
{
    system("cls");   // Clear screen on Windows and Unix
    system("clear"); // Clear screen on Linux
}

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

void perhitunganTransaksi()
{
    char input[255];
    double jumlahTransaksi;
    int jumlahCoupon = 0;
    double discount = 0;
    double totalBayar;

    getchar();

    printf("Masukkan total pembelian: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from the end of the string.
    input[strlen(input) - 1] = '\0';

    jumlahTransaksi = strtodoub(input);

    if (jumlahTransaksi == 0)
    {
        printf("input tidak valid \n");
        return;
    }

    if (jumlahTransaksi >= 100000)
    {
        jumlahCoupon = jumlahTransaksi / 100000;
        discount = jumlahTransaksi * 0.1;
    }

    totalBayar = jumlahTransaksi - discount;

    clearScreen();
    printf("==============================\n");
    printf("Jumlah transaksi adalah: %.2lf \n", jumlahTransaksi);
    printf("Jumlah kupon undian yang diterima: %d\n", jumlahCoupon);
    if (discount > 0)
    {
        printf("Mendapat diskon sebesar: %.2lf\n", discount);
    }
    printf("Total yang harus dibayar: %.2lf\n", totalBayar);
    printf("=============================\n");
}

void menu(bool *lanjut)
{
    int choice;

    printf("Pilih menu berikut: \n");
    printf("1. Menghitung belanjaan\n");
    printf("2. Exit\n");
    printf("Pilih 1 atau 2: ");
    scanf("%d", &choice);
    clearScreen();
    switch (choice)
    {
    case 1:
        perhitunganTransaksi();
        *lanjut = true;
        break;
    case 2:
        printf("Terima kasih. Sampai jumpa!\n");
        *lanjut = false;
        break;
    default:
        printf("Input Tidak valid! \n");
        *lanjut = true;
        break;
    }
}

int main()
{
    bool lanjut;
    do
    {
        printf("==============================\n");
        printf("            Group 6           \n");
        printf("==============================\n");
        printf("  Program supermarket week 7  \n");
        printf("==============================\n");
        menu(&lanjut);
    } while (lanjut);

    return 0;
}