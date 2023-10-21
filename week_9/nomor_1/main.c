#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char kode_buku[50];
    char nama_buku[50];
    char jenis_buku[50];
    double harga;
} BUKU;

BUKU buku;

int sequence, sequence2 = 0;

BUKU arrayBuku[100];
BUKU arrayHistory[100];

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

void clearScreen()
{
    system("cls");   // Clear screen on Windows and Unix
    system("clear"); // Clear screen on Linux
}

void getBuku()
{
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    char line[256];
    sequence = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%49[^|]| %49[^|]| %49[^|]| %lf", buku.kode_buku, buku.nama_buku, buku.jenis_buku, &buku.harga) == 4)
        {
            arrayBuku[sequence] = buku;
            sequence++;
        }
        else
        {
            printf("Baris tidak valid: %s", line);
        }
    }
    fclose(file);
}

void getHistory()
{
    FILE *file = fopen("datapembelian.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    char line[256];
    sequence2 = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%49[^|]| %49[^|]| %49[^|]| %lf", buku.kode_buku, buku.nama_buku, buku.jenis_buku, &buku.harga) == 4)
        {
            int nomor = sequence2 + 1;
            arrayHistory[sequence2] = buku;
            printf("%-12d| %-25s| %-20s\n", nomor, buku.nama_buku, buku.kode_buku);
            sequence2++;
        }
        else
        {
            printf("Baris tidak valid: %s", line);
        }
    }
    fclose(file);
}

void ListBuku()
{
    printf("%-12s| %-25s| %-20s\n", "Nomor", "Judul Buku", "Kode Buku");

    for (int i = 0; i < sequence; i++)
    {
        /* code */
        int nomor = i + 1;
        printf("%-12d| %-25s| %-20s\n", nomor, arrayBuku[i].nama_buku, arrayBuku[i].kode_buku);
    }
}

void createData()
{
    FILE *file;
    char input[100];

    printf("Kode Buku : ");
    fgets(buku.kode_buku, sizeof(buku.kode_buku), stdin);
    buku.kode_buku[strcspn(buku.kode_buku, "\n")] = '\0';

    printf("Input Nama Buku : ");
    fgets(buku.nama_buku, sizeof(buku.nama_buku), stdin);
    buku.nama_buku[strcspn(buku.nama_buku, "\n")] = '\0';

    printf("Input Jenis Buku : ");
    fgets(buku.jenis_buku, sizeof(buku.jenis_buku), stdin);
    buku.jenis_buku[strcspn(buku.jenis_buku, "\n")] = '\0';

    printf("Input Harga : ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    buku.harga = strtod(input, NULL);

    printf("harga: %lf", buku.harga);

    file = fopen("databuku.txt", "a");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    fprintf(file, "%s|%s|%s|%.2lf\n", buku.kode_buku, buku.nama_buku, buku.jenis_buku, buku.harga);
    fclose(file);

    printf("Berhasil menambah data\n");
    getBuku();
}

void transaction()
{
    getBuku();
    FILE *file;
    int nomor;
    char input[255];

    ListBuku();

    file = fopen("datapembelian.txt", "a");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    printf("Masukkan nomor buku yang ingin dibeli [1 - %d]: ", sequence);
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';
    nomor = strtoint(input);
    if (nomor >= 1 && nomor <= sequence)
    {
        fprintf(file, "%s | %s | %s | %.2lf\n", arrayBuku[nomor - 1].kode_buku, arrayBuku[nomor - 1].nama_buku, arrayBuku[nomor - 1].jenis_buku, arrayBuku[nomor - 1].harga);
    }
    else
    {
        printf("Index tidak valid");
    }
    getBuku();
    fclose(file);
}

void viewHistory()
{
    FILE *file = fopen("datapembelian.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }
    printf("===============================================================\n");
    printf("Data pembelian buku di datapembelian.txt:\n");
    printf("\n");
    printf("===============================================================\n");
    printf("%-20s| %-25s| %-20s| %-20s\n", "Kode Buku", "Judul Buku", "Jenis Buku", "Harga");
    char line[256];
    BUKU book;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%49[^|]| %49[^|]| %49[^|]| %lf", book.kode_buku, book.nama_buku, book.jenis_buku, &book.harga) == 4)
        {
            printf("%-20s| %-25s| %-20s| %.2lf\n", book.kode_buku, book.nama_buku, book.jenis_buku, book.harga);
        }
        else
        {
            printf("Baris tidak valid: %s", line);
        }
    }
    fclose(file);
    printf("===============================================================\n");
}

void ViewBuku()
{
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }
    printf("===============================================================\n");
    printf("Data Buku di Databuku.txt:\n");
    printf("\n");

    char line[256];
    BUKU book;
    printf("===============================================================\n");
    printf("%-20s| %-25s| %-20s| %-20s\n", "Kode Buku", "Judul Buku", "Jenis Buku", "Harga");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%49[^|]| %49[^|]| %49[^|]| %lf", book.kode_buku, book.nama_buku, book.jenis_buku, &book.harga) == 4)
        {
            printf("%-20s| %-25s| %-20s| %.2lf\n", book.kode_buku, book.nama_buku, book.jenis_buku, book.harga);
        }
        else
        {
            printf("Baris tidak valid: %s", line);
        }
    }
    fclose(file);
    printf("===============================================================\n");
}

void deleteHistory()
{
    FILE *file;
    int nomor;
    char input[255];

    getHistory();

    printf("Masukkan nomor buku yang ingin dihapus [1 - %d] : ", sequence2);
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';
    nomor = strtoint(input);

    if (nomor >= 1 && nomor <= sequence2)
    {
        for (int i = nomor - 1; i < sequence2 - 1; i++)
        {
            arrayBuku[i] = arrayBuku[i + 1];
        }
        sequence2--;

        remove("datapembelian.txt");

        FILE *file = fopen("datapembelian.txt", "a");
        if (file == NULL)
        {
            perror("Gagal membuka file");
            return;
        }

        for (int i = 0; i < sequence2; i++)
        {
            fprintf(file, "%s | %s | %s | %.2lf \n", arrayBuku[i].kode_buku, arrayBuku[i].nama_buku, arrayBuku[i].jenis_buku, arrayBuku[i].harga);
        }

        printf("Data succes delete\n");
        fclose(file);
    }
    else
    {
        printf("Index tidak valid\n");
    }
    printf("\n");
}

void deleteBuku()
{
    getBuku();
    FILE *file;
    int nomor;
    char input[255];

    ListBuku();

    printf("Masukkan nomor buku yang ingin dihapus [1 - %d] : ", sequence);
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = '\0';
    nomor = strtoint(input);

    if (nomor >= 1 && nomor <= sequence)
    {
        for (int i = nomor - 1; i < sequence - 1; i++)
        {
            arrayBuku[i] = arrayBuku[i + 1];
        }
        sequence--;

        remove("databuku.txt");

        FILE *file = fopen("databuku.txt", "a");
        if (file == NULL)
        {
            perror("Gagal membuka file");
            return;
        }

        for (int i = 0; i < sequence; i++)
        {
            fprintf(file, "%s | %s | %s | %.2lf \n", arrayBuku[i].kode_buku, arrayBuku[i].nama_buku, arrayBuku[i].jenis_buku, arrayBuku[i].harga);
        }
        fclose(file);
        printf("Data succes delete");
    }
    else
    {
        printf("Index tidak valid");
    }
}

int main()
{
    int choice;

    printf("==============================\n");
    printf("            Group 6           \n");
    printf("==============================\n");
    printf("       Program toko buku      \n");
    printf("==============================\n");

    while (1)
    {
        printf("Pilih Menu: \n");
        printf("(1) Insert data buku \n");
        printf("(2) View History \n");
        printf("(3) View Buku \n");
        printf("(4) Beli Buku\n");
        printf("(5) Delete Buku\n");
        printf("(6) Delete data history\n");
        printf("(7) Keluar\n");

        printf("Pilih opsi (1/2/3/4/5): ");
        scanf("%d", &choice);

        getchar();
        clearScreen();

        switch (choice)
        {
        case 1:
            createData();
            break;
        case 2:
            viewHistory();
            break;
        case 3:
            ViewBuku();
            break;
        case 4:
            transaction();
            break;
        case 5:
            deleteBuku();
            break;
        case 6:
            deleteHistory();
            break;
        case 7:
            exit(0); // Keluar dari program
        default:
            printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    }

    return 0;
}
