#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main(void)
{
    char input[100];
    double hour;

    printf("Masukkan bilangan pecahan: ");
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
            printf("%lf\n", calculateHour(hour));
        }
    }
    else
    {
        printf("Input bukan bilangan pecahan.\n");
    }

    return 0;
}
