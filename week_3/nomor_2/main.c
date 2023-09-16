#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

double average(double totalNilai)
{
    double rataRata = totalNilai / 5;
    return rataRata;
}

char grade(double value)
{
    char grade;

    if (value <= 55)
    {
        grade = 'E';
    }
    else if (value <= 65)
    {
        grade = 'D';
    }
    else if (value <= 75)
    {
        grade = 'C';
    }
    else if (value <= 85)
    {
        grade = 'B';
    }
    else if (value <= 100)
    {
        grade = 'A';
    }
    return grade;
}

int main()
{
    double quiz, tugas, absen, praktek, uas, totalNilai;
    int mahasiswa = 0, limit; // Initialize mahasiswa with 0
    char nama[100];

    printf("==============================\n");
    printf("            Group 6           \n");
    printf("==============================\n");
    printf("  Program perhitungan nilai   \n");
    printf("==============================\n");

    printf("Input jumlah mahasiswa: ");

    if (scanf("%d", &limit) != 1)
    {
        printf("Input must be a valid integer\n");
        return 1; // Exit the program with an error code
    }

    while (mahasiswa < limit)
    {
        printf("Input nama mahasiswa: ");
        scanf("%s", nama);

        // Input nilai quiz
        printf("Input nilai quiz: ");
        if (scanf("%lf", &quiz) != 1)
        {
            printf("Input must be a valid double\n");
            return 1; // Exit the program with an error code
        }
        char finalGradeQuiz = grade(quiz);
        printf("Grade %c \n", finalGradeQuiz);

        // Input nilai tugas
        printf("Input nilai tugas: ");
        if (scanf("%lf", &tugas) != 1)
        {
            printf("Input must be a valid double\n");
            return 1; // Exit the program with an error code
        }
        char finalGradeTugas = grade(tugas);
        printf("Grade %c \n", finalGradeTugas);

        // Input nilai absen
        printf("Input nilai absen: ");
        if (scanf("%lf", &absen) != 1)
        {
            printf("Input must be a valid double\n");
            return 1; // Exit the program with an error code
        }
        char finalGradeAbsen = grade(absen);
        printf("Grade %c \n", finalGradeAbsen);

        // Input nilai praktek
        printf("Input nilai praktek: ");
        if (scanf("%lf", &praktek) != 1)
        {
            printf("Input must be a valid double\n");
            return 1; // Exit the program with an error code
        }
        char finalGradePraktek = grade(praktek);
        printf("Grade %c \n", finalGradePraktek);

        // Input nilai UAS
        printf("Input nilai UAS: ");
        if (scanf("%lf", &uas) != 1)
        {
            printf("Input must be a valid double\n");
            return 1; // Exit the program with an error code
        }
        char finalGradeUas = grade(uas);
        printf("Grade %c \n", finalGradeUas);

        // Hitung rata-rata
        totalNilai = quiz + tugas + absen + praktek + uas;
        double rataRata = average(totalNilai);
        printf("Nilai rata-rata mahasiswa: %lf\n", rataRata);
        printf("==============================\n");
        // Pengecekan lulus/tidak lulus
        if (finalGradeQuiz == 'D' || finalGradeAbsen == 'D' || finalGradeTugas == 'D' || finalGradePraktek == 'D' || finalGradeUas == 'D' || finalGradeQuiz == 'E' || finalGradeAbsen == 'E' || finalGradeTugas == 'E' || finalGradePraktek == 'E' || finalGradeUas == 'E')
        {
            printf("Mahasiswa tidak lulus\n");
        }
        else
        {
            printf("Mahasiswa lulus\n");
        }
        printf("==============================\n");
        printf("==============================\n");
        mahasiswa++;
    }

    return 0; // Program selesai dengan sukses
}
