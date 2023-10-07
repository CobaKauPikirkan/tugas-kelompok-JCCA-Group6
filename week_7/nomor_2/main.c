#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

enum GajiPokok {
    D1 = 2500000,
    D2 = 2000000,
    D3 = 1500000
};

enum Lemburan {
    d1 = 10000,
    d2 = 5000,
    d3 = 2500
};

typedef struct {
    char nip[255];
    char fullname[255];
    char address[255];
    char phoneNumber[255];
    char position[255];
    char golongan[255];
    char jumlahLembur[255];
    enum GajiPokok gajiPokok;
    enum Lemburan lemburan;
} Employee;


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
void toUpperCase(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = toupper(str[i]);
    }
}

void input1()
{
    Employee employee;

    printf("Masukan nomor induk pegawai (NIP): ");
    fgets(employee.nip, sizeof(employee.nip), stdin);
    printf("Masukan nama pegawai: ");
    fgets(employee.fullname, sizeof(employee.fullname), stdin);
    printf("Masukan alamat pegawai: ");
    fgets(employee.address, sizeof(employee.address), stdin);
    printf("Masukan No. HP: ");
    fgets(employee.phoneNumber, sizeof(employee.phoneNumber), stdin);
    printf("Masukan jabatan pegawai: ");
    fgets(employee.position, sizeof(employee.position), stdin);
    printf("Masukan golongan pegawai: ");
    fgets(employee.golongan, sizeof(employee.golongan), stdin);
    toUpperCase(employee.golongan); // Convert golongan to uppercase

    if (strcmp(employee.golongan, "D1\n") == 0)
    {
        employee.gajiPokok = D1;
    }
    else if (strcmp(employee.golongan, "D2\n") == 0)
    {
        employee.gajiPokok = D2;
    }
    else if (strcmp(employee.golongan, "D3\n") == 0)
    {
        employee.gajiPokok = D3;
    }
    else
    {
        printf("Invalid input golongan pegawai !");
        return;
    }
    

    clearScreen();
    printf("==============================\n");
    printf("\n NIP: %s", employee.nip);
    printf("\n Nama: %s", employee.fullname);
    printf("\n Alamat: %s", employee.address);
    printf("\n No. HP: %s", employee.phoneNumber);
    printf("\n Jabatan: %s", employee.position);
    printf("\n Golongan: %s", employee.golongan);
    printf("\n Gaji: %d", employee.gajiPokok);
    printf("\n==============================\n");
}

void input2()
{
    Employee employee;
    // char inputLembur[10];
    int jamLembur, totalGaji;

    printf("Masukan nomor induk pegawai (NIP): ");
    fgets(employee.nip, sizeof(employee.nip), stdin);

    printf("Masukan golongan pegawai: ");
    fgets(employee.golongan, sizeof(employee.golongan), stdin);
    toUpperCase(employee.golongan); // Convert golongan to uppercase

    printf("Masukan jumlah jam lembur: ");
    fgets(employee.jumlahLembur, sizeof(employee.jumlahLembur), stdin);
    employee.jumlahLembur[strlen(employee.jumlahLembur) - 1] = '\0';

    jamLembur = strtoint(employee.jumlahLembur);

    if (strcmp(employee.golongan, "D1\n") == 0)
    {
        employee.gajiPokok = D1;
        employee.lemburan = d1;
        totalGaji = (jamLembur * employee.lemburan) + employee.gajiPokok;
    }
    else if (strcmp(employee.golongan, "D2\n") == 0)
    {
        employee.gajiPokok = D2;
        employee.lemburan = d2;
        totalGaji = (jamLembur * employee.lemburan) + employee.gajiPokok;
    }
    else if (strcmp(employee.golongan, "D3\n") == 0)
    {
        employee.gajiPokok = D3;
        employee.lemburan = d3;
        totalGaji = (jamLembur * employee.lemburan) + employee.gajiPokok;
    }
    else
    {
        printf("Invalid input!");
        return;
    }

    clearScreen();
    printf("==============================\n");
    printf("\n NIP: %s", employee.nip);
    printf("\n Golongan: %s", employee.golongan);
    printf("\n Jam lembur %d", jamLembur);
    printf("\n Gaji bulan ini: %d", totalGaji);
    printf("\n==============================\n");
}

void menu(bool *lanjut)
{
    int choice;

    printf("Pilih menu berikut: \n");
    printf("1. Input 1\n");
    printf("2. Input 2\n");
    printf("3. Exit\n");
    printf("Pilih 1 / 2 / 3: ");
    scanf("%d", &choice);
    clearScreen();
    getchar();
    switch (choice)
    {
    case 1:
        input1();
        *lanjut = true;
        break;
    case 2:
        input2();
        *lanjut = true;
        break;
    case 3:
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
        printf("\n");
        printf("==============================\n");
        printf("            Group 6           \n");
        printf("==============================\n");
        printf("   Program prehitungan gaji   \n");
        printf("==============================\n");
        menu(&lanjut);
    } while (lanjut);

    return 0;
}