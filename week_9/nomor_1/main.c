#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

typedef struct
{
    char kode_buku[50];
    char nama_buku[50];
    char jenis_buku[50];
    double harga;
} BUKU;

BUKU buku;

BUKU arrayBuku[100];

void getBuku()
{
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    printf("Data Buku di Databuku.txt:\n");

    char line[256];

    int sequence = 0;

    BUKU book;

    while (fscanf(file, "%49s %49s %49s %lf", book.kode_buku, book.nama_buku, book.jenis_buku, &book.harga) != EOF)
    {
        // todo define array struct
        // *arrayBuku[sequence] = book;

        sequence++;
    }

    fclose(file);
}

void ListBuku()
{
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    printf("Data Buku di Databuku.txt:\n");

    char line[256];

    int sequence = 1;
    BUKU book;

    while (fscanf(file, "%49s %49s %49s %lf", book.kode_buku, book.nama_buku, book.jenis_buku, &book.harga) != EOF)
    {
        printf("%d.)", sequence);
        printf("%s (%s)\n", book.nama_buku, book.kode_buku);

        sequence += 1;
    }

    fclose(file);
}

void createData()
{
    FILE *file;
    char input[100];
    // file = fopen("databuku.txt", "a");
    // if (file == NULL)
    // {
    //     printf("Gagal membuka file");
    //     return;
    // };

    // char text[100] = "Tes fwrite\n";

    // fwrite(text, 1, sizeof(text), file);
    // fprintf(file, "%s",text);
    // fclose(file);

    // printf("Kode Buku : ");
    // fgets(buku.kode_buku, sizeof(buku.kode_buku), stdin );
    // buku.kode_buku[strcspn(buku.kode_buku, "\n")] = '\0';
    // printf("Input Nama Buku : ");
    // fgets(buku.nama_buku, sizeof(buku.nama_buku), stdin );
    // buku.nama_buku[strcspn(buku.nama_buku, "\n")] = '\0';
    // printf("Input Jenis Buku : ");
    // fgets(buku.jenis_buku, sizeof(buku.jenis_buku), stdin );
    // buku.jenis_buku[strcspn(buku.jenis_buku, "\n")] = '\0';
    // printf("Input Harga : ");
    // fgets(input, sizeof(input), stdin );
    // input[strlen(input) - 1] = '\0';
    // buku.harga = strtodoub(input);

    // printf("harga: %lf", buku.harga);

    // file = fopen("databuku.txt", "a");
    // if (file == NULL)
    // {
    //     perror("Gagal membuka file");
    //     return;
    // };

    // fwrite(&buku, sizeof(BUKU), 1, file);
    // fclose(file);

    // printf("Berhasil menambah data\n");

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
    buku.harga = strtod(input, NULL);

    printf("harga: %lf", buku.harga);

    file = fopen("databuku.txt", "a");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    fprintf(file, "%s %s %s %.2lf\n", buku.kode_buku, buku.nama_buku, buku.jenis_buku, buku.harga);
    fclose(file);

    printf("Berhasil menambah data\n");
}

void transaction()
{

    FILE *file;
    char kode_buku[50];
    int quantity;

    ListBuku();

    printf("Masukkan Kode Buku yang ingin dibeli: ");
    fgets(kode_buku, sizeof(kode_buku), stdin);
    kode_buku[strcspn(kode_buku, "\n")] = '\0';

    file = fopen("databuku.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    BUKU book;
    int found = 0;

    while (fscanf(file, "%49s %49s %49s %lf", book.kode_buku, book.nama_buku, book.jenis_buku, &book.harga) != EOF)
    {

        
        if (strcmp(kode_buku, book.kode_buku) == 0)
        {
            found = 1;
            printf("Buku yang ditemukan:\n");
            printf("Kode Buku: %s\n", book.kode_buku);
            printf("Nama Buku: %s\n", book.nama_buku);
            printf("Jenis Buku: %s\n", book.jenis_buku);
            printf("Harga: %lf\n", book.harga);

            printf("Masukkan jumlah yang ingin dibeli: ");
            scanf("%d", &quantity);

            // Lakukan logika pembelian di sini
            // Misalnya, hitung total harga dan update stok buku.

            // Setelah pembelian selesai, Anda dapat menyimpan perubahan ke file "databuku.txt" jika diperlukan.

            break;
        }
    }

    if (!found)
    {
        printf("Buku dengan kode %s tidak ditemukan.\n", kode_buku);
    }

    fclose(file);
}

void viewHistory()
{
}

void ViewBuku()
{
    FILE *file = fopen("databuku.txt", "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        return;
    }

    printf("Data Buku di Databuku.txt:\n");

    char line[256];
    BUKU book;

    while (fscanf(file, "%49s %49s %49s %lf", book.kode_buku, book.nama_buku, book.jenis_buku, &book.harga) != EOF)
    {
        printf("Kode Buku: %s\n", book.kode_buku);
        printf("Nama Buku: %s\n", book.nama_buku);
        printf("Jenis Buku: %s\n", book.jenis_buku);
        printf("Harga: %lf\n", book.harga);
        printf("----------------------------\n");
    }

    fclose(file);
}

void deleteHistory()
{
}

void deleteBuku()
{
    printf("");
}

int main()
{
    int choice;

    getBuku();

    while (1)
    {
        printf("MenuInsertaBukugram: \n");
        printf("(1) Insert data buku \n");
        printf("(2) View History \n");
        printf("(3) View Buku \n");
        printf("(4) Beli Buku\n");
        printf("(5) Delete Buku\n");
        printf("(6) Delete data\n");
        printf("(7) Keluar\n");

        printf("Pilih opsi (1/2/3/4/5): ");
        scanf("%d", &choice);

        getchar();

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
