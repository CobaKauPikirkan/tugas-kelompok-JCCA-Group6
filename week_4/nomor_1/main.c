#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

void clearScreen()
{
    system("cls");   // Clear screen on Windows and Unix
    system("clear"); // Clear screen on Linux
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

double calculateBill(int hour, double price)
{
    return price * hour;
}

double calculateDiscount(int hour, double bill)
{
    double sale = 0;

    // Checking playing hour for decide the discount
    if (hour > 4)
    {
        sale = bill * 0.10;
    }

    if (hour > 6)
    {
        sale = bill * 0.15;
    }

    if (hour > 8)
    {
        sale = bill * 0.20;
    }

    if (hour > 10)
    {
        sale = bill * 0.25;
    }

    return sale;
}

int main(void)
{
    char input[255];
    double pricePerHour = 10000;
    int playingHour;
    double bill = 0;
    double discount = 0;
    double totalBill = 0;

    printf("==============================\n");
    printf("            Group 6           \n");
    printf("==============================\n");
    printf("======= Program Warnet =======\n");
    printf("==============================\n");

    do
    {
        printf("Masukan jumlah waktu bermain (jam): ");
        fgets(input, sizeof(input), stdin);

        // Remove the newline character from the end of the string.
        input[strlen(input) - 1] = '\0';

        // Convert input to integer
        playingHour = strtoint(input);

        // Print invalid message
        if (playingHour == 0)
        {
            printf("Input tidak valid\n\n");
        }
        else
        {
            // Calculate the bill
            bill = calculateBill(playingHour, pricePerHour);
            // Calculate the discount
            discount = calculateDiscount(playingHour, bill);
            // Calculate final bill
            totalBill = bill - discount;
        }
    } while (playingHour == 0); // Looping while playing hour is not valid

    clearScreen();

    setlocale(LC_NUMERIC, ""); // Set local formatting
    printf("==============================\n");
    printf("            Group 6           \n");
    printf("==============================\n");
    printf("======= Program Warnet =======\n");
    printf("==============================\n");
    printf("\n");

    printf("Waktu bermain anda adalah %d jam\n", playingHour);
    printf("Harga yang harus dibayar: Rp.%.2lf\n", bill);

    // Display discount if possible
    if (discount > 0)
    {
        printf("Potongan harga: Rp.%.2lf\n", discount);
    }

    printf("Total yang harus dibayar: Rp.%.2lf\n", totalBill);
    printf("==============================\n");
}