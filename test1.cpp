#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 8
#define MAX_FIELD_LENGTH 50

int main() {
    FILE *file;
    char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];  // Store CSV data
    char buffer[1024];  // Buffer to read each line from the file

    file = fopen("file.csv", "r");

    if (file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Read data from file
    int row = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL && row < MAX_ROWS) {
        int col = 0;
        char *token = strtok(buffer, ",\n");  // Split the line into tokens using ',' or newline

        while (token != NULL && col < MAX_COLS) {
            strcpy(data[row][col], token);  // Store each field in data[row][col]
            token = strtok(NULL, ",\n");
            col++;
        }

        row++;
    }

    fclose(file);

    // Search for a specific value
    char search_value[MAX_FIELD_LENGTH];  // Specify the value to search for
    printf("Enter the value to search: ");
    scanf("%s", search_value);

    // Display rows containing the search value
    int found = 0;
    printf("Rows containing '%s':\n", search_value);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (strcmp(data[i][j], search_value) == 0) {
                found = 1;
                for (int k = 0; k < MAX_COLS; k++) {
                    printf("%-25s", data[i][k]);  // Print the entire row
                }
                printf("\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Value not found in the table.\n");
    }

    return 0;
}
