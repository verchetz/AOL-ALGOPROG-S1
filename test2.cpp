#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100  // Maximum rows to read from the file
#define MAX_COLS 10   // Maximum columns to read from the file
#define MAX_FIELD_LENGTH 50  // Maximum length of a field in the CSV

int main() {
    FILE *file;
    char line[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];  // Store CSV data
    char buffer[1024];  // Buffer to read each line from the file
    int limiter = 0;

    file = fopen("file.csv", "r");  // Replace "data.csv" with your file name

    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("Jumlah row: ");
    scanf("%d", &limiter); getchar();

    int row = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL && row < limiter+1) {
        int col = 0;
        char *token = strtok(buffer, ",\n");  // Split the line into tokens using ',' or newline

        while (token != NULL && col < MAX_COLS) {
            strcpy(line[row][col], token);  // Store each field in line[row][col]
            printf("%-22s", line[row][col]);  // Display each field (tab-separated)
            token = strtok(NULL, ",\n");
            col++;
        }

        printf("\n");  // Move to the next line for the next row
        row++;
    }

    fclose(file);
    return 0;
}
