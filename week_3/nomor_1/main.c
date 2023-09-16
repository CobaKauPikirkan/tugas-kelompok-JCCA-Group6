#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

// Fungsi untuk memeriksa apakah string adalah double
bool isDouble(const char *str)
{
    // Coba mengonversi string menjadi double
    char *endptr;
    strtod(str, &endptr);

    // Jika endptr sama dengan str, artinya string tidak valid sebagai double
    return *endptr == '\0';
}

double calculateDiscount(double amount, double discount)
{
    double const result = amount - (amount * discount);

    return result;
}

double calculateHour(double hour)
{
    double pricePerHour = 10000;

    double amount = hour * pricePerHour;

    if (hour > 4 && hour <= 6)
    {
        return calculateDiscount(amount, 0.10);
    }
    else if (hour > 6 && hour <= 8)
    {
        return calculateDiscount(amount, 0.15);
    }
    else if (hour > 8 && hour <= 10)
    {
        return calculateDiscount(amount, 0.20);
    }
    else if (hour > 10)
    {
        return calculateDiscount(amount, 0.25);
    }
    else
    {
        return amount;
    }
}

void clearScreen()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix/Linux and macOS
#endif
}

int main(void)
{
    char input[100];
    double hour;
    char response[10];

    do
    {
        printf("==============================\n");
        printf("            Group 6           \n");
        printf("==============================\n");
        printf("======= Program Warnet =======\n");
        printf("==============================\n");

        printf("Masukkan jumlah jam: ");
        scanf("%s", input);

        if (isDouble(input))
        {
            hour = atof(input); // Konversi input menjadi double

            if (hour <= 0)
            {
                printf("Input tidak boleh kurang dari 0\n");
            }
            else
            {
                printf("%.2lf\n", calculateHour(hour));
            }
        }
        else
        {
            printf("Input bukan angka.\n");
        }

        printf("Apakah Anda ingin melakukan input lagi? (y/n): ");
        scanf("%s", response);

        clearScreen();

    } while (strcmp(response, "y") == 0);

    return 0;
}
