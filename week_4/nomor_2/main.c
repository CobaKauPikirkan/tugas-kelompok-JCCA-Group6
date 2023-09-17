#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// struct of student for store data
struct Student
{
    char fullname[255];
    double quizScore;
    double assignmentScore;
    double attendanceScore;
    double practiceScore;
    double examScore;
};

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

char grading(double score)
{
    // Return the grade
    if (score <= 55)
    {
        return 'E';
    }

    if (score <= 65)
    {
        return 'D';
    }

    if (score <= 75)
    {
        return 'C';
    }

    if (score <= 85)
    {
        return 'B';
    }

    if (score <= 100)
    {
        return 'A';
    }

    return 'F';
}

void checkstats(char grades[])
{
    int iscontain = 0;
    for (int i = 0; i < strlen(grades); i++)
    {
        // Check if grade is E or D
        if (grades[i] == 'D' || grades[i] == 'E')
        {
            iscontain = 1;
            break;
        }
    }

    // Check if true will be fail
    if (iscontain)
    {
        printf("Tidak lulus\n\n\n");
    }
    else
    {
        printf("Lulus\n\n\n");
    }
}

double average(double scores[], int length)
{
    // Default value
    double sum = 0;

    // Looping for sum array
    for (int i = 0; i < length; i++)
    {
        sum += scores[i];
    }

    // Sum of score division length of score
    return sum / length;
}

int main(void)
{
    char input[255];
    char *endptr;
    int numOfStudent;
    int minimumStudent = 10;

    // Array of student scores
    double *avgStudentScores = calloc(10, sizeof(double));
    printf("==============================\n");
    printf("            Group 6           \n");
    printf("==============================\n");
    printf("  Program perhitungan nilai   \n");
    printf("==============================\n");

    do
    {
        do
        {
            printf("Masukan jumlah mahasiswa yang ingin di input(e.g: 10): ");

            // Get input from console
            fgets(input, sizeof(input), stdin);

            // Remove the newline character from the end of the string.
            input[strlen(input) - 1] = '\0';

            // Convert input from console to int
            numOfStudent = strtoint(input);

            // Validation input if return is 0
            if (numOfStudent == 0)
            {
                printf("Invalid input\n\n");
            }
            else if (numOfStudent < minimumStudent)
            {
                printf("Jumlah minimal mahasiswa adalah %d\n\n", minimumStudent);
            }
            else
            {
                // Clear console
                clearScreen();

                // Array of struct students
                struct Student students[numOfStudent];

                // Change size of array of student scores
                avgStudentScores = realloc(avgStudentScores, numOfStudent * sizeof(double));

                // Loop input student data
                for (int i = 0; i < numOfStudent; i++)
                {

                    // Variables for stores data from input
                    char inputFullname[255];
                    char inputQuizScore[255];
                    char inputAssignmentScore[255];
                    char inputPracticeScore[255];
                    char inputAttendanceScore[255];
                    char inputExamScore[255];

                    // Variables for stores data to struct
                    double quizScore;
                    double assignmentScore;
                    double attendanceScore;
                    double practiceScore;
                    double examScore;

                    int seq = i + 1;

                    printf("Input data Mahasiswa ke %d\n", seq);

                    // Input fullname
                    printf("Masukan nama mahasiswa: ");
                    fgets(inputFullname, sizeof(inputFullname), stdin);

                    inputFullname[strlen(inputFullname) - 1] = '\0';

                    // Input quiz score
                    do
                    {
                        printf("Masukan nilai quiz: ");
                        fgets(inputQuizScore, sizeof(inputQuizScore), stdin);

                        inputQuizScore[strlen(inputQuizScore) - 1] = '\0';

                        // Convert string to double
                        quizScore = strtodoub(inputQuizScore);

                        // Check validation if false
                        if (quizScore == 0 || quizScore > 100)
                        {
                            printf("Nilai tidak valid. Mohon untuk input angka\n\n");
                        }
                    } while (quizScore == 0 || quizScore > 100);

                    // Input assignment score
                    do
                    {
                        printf("Masukan nilai tugas: ");
                        fgets(inputAssignmentScore, sizeof(inputAssignmentScore), stdin);

                        inputAssignmentScore[strlen(inputAssignmentScore) - 1] = '\0';

                        // Convert string to double
                        assignmentScore = strtodoub(inputAssignmentScore);

                        // Check validation if false
                        if (assignmentScore == 0 || assignmentScore > 100)
                        {
                            printf("Nilai tidak valid. Mohon untuk input angka\n\n");
                        }
                    } while (assignmentScore == 0 || assignmentScore > 100);

                    // Input attendance score
                    do
                    {
                        printf("Masukan nilai absensi: ");
                        fgets(inputAttendanceScore, sizeof(inputAttendanceScore), stdin);

                        inputAttendanceScore[strlen(inputAttendanceScore) - 1] = '\0';

                        // Convert string to double
                        attendanceScore = strtodoub(inputAttendanceScore);

                        // Check validation if false
                        if (attendanceScore == 0 || attendanceScore > 100)
                        {
                            printf("Nilai tidak valid. Mohon untuk input angka\n\n");
                        }
                    } while (attendanceScore == 0 || attendanceScore > 100);

                    // Input practice score
                    do
                    {
                        printf("Masukan nilai praktek: ");
                        fgets(inputPracticeScore, sizeof(inputPracticeScore), stdin);

                        inputPracticeScore[strlen(inputPracticeScore) - 1] = '\0';

                        // Convert string to double
                        practiceScore = strtodoub(inputPracticeScore);

                        // Check validation if false
                        if (practiceScore == 0 || practiceScore > 100)
                        {
                            printf("Nilai tidak valid. Mohon untuk input angka\n\n");
                        }
                    } while (practiceScore == 0 || practiceScore > 100);

                    // Input exam score
                    do
                    {
                        printf("Masukan nilai UAS: ");
                        fgets(inputExamScore, sizeof(inputExamScore), stdin);

                        inputExamScore[strlen(inputExamScore) - 1] = '\0';

                        // Convert string to double
                        examScore = strtodoub(inputExamScore);

                        // Check validation if false
                        if (examScore == 0 || examScore > 100)
                        {
                            printf("Nilai tidak valid. Mohon untuk input angka\n\n");
                        }
                    } while (examScore == 0 || examScore > 100);

                    // Store data to struct
                    strcpy(students[i].fullname, inputFullname);
                    students[i].quizScore = quizScore;
                    students[i].assignmentScore = assignmentScore;
                    students[i].attendanceScore = attendanceScore;
                    students[i].practiceScore = practiceScore;
                    students[i].examScore = examScore;

                    clearScreen();
                }
                printf("==============================\n");
                printf("            Group 6           \n");
                printf("==============================\n");
                printf("  Program perhitungan nilai   \n");
                printf("==============================\n");

                printf("Mahasiswa\n\n");

                // Looping for display student
                for (int i = 0; i < numOfStudent; i++)
                {
                    // Grouping score
                    double scores[] = {
                        students[i].quizScore,
                        students[i].assignmentScore,
                        students[i].attendanceScore,
                        students[i].practiceScore,
                        students[i].examScore};

                    char quizGrade = grading(students[i].quizScore);
                    char assignmentGrade = grading(students[i].assignmentScore);
                    char attendanceGrade = grading(students[i].attendanceScore);
                    char practiceGrade = grading(students[i].practiceScore);
                    char examGrade = grading(students[i].examScore);

                    // Grouping grade
                    char grades[] = {
                        quizGrade,
                        assignmentGrade,
                        attendanceGrade,
                        practiceGrade,
                        practiceGrade,
                        examGrade};

                    printf("Nama lengkap: %s\n", students[i].fullname);
                    printf("Nilai Quiz: %c\n", grading(students[i].quizScore));
                    printf("Nilai Tugas: %c\n", grading(students[i].assignmentScore));
                    printf("Nilai Absensi: %c\n", grading(students[i].attendanceScore));
                    printf("Nilai Praktik: %c\n", grading(students[i].practiceScore));
                    printf("Nilai UAS: %c\n", grading(students[i].examScore));

                    // Calculate average of all scores
                    double avg = average(scores, sizeof(scores) / sizeof(double));
                    // Print average of scores
                    printf("Nilai rata - rata: %.2f\n", avg);

                    printf("Status Mahasiswa: ");
                    checkstats(grades); // Check the grades if passed

                    // Add average score of student
                    avgStudentScores[i] = avg;
                    printf("\n");
                }
            }
        } while (numOfStudent < minimumStudent); // Loop while minimum student not achieved
    } while (numOfStudent == 0);                 // Loop while input student invalid

    // double totalAverage = avgStudentScores;

    // Print average all of student
    printf(
        "Nilai rata - rata dari %d mahasiswa adalah: %.2f \n",
        numOfStudent,
        average(avgStudentScores, sizeof(avgStudentScores)));
    printf("==============================\n");
}