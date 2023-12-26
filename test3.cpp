#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 8
#define MAX_FIELD_LENGTH 50

// Function to export data to a new CSV file
void exportToCSV(char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH], int rows, char *filename) {
    FILE *file;
    char fullFilename[100];
        // Check if the filename contains ".csv"
    if (strstr(filename, ".csv") == NULL) {
        // If not, append ".csv" to the filename
        snprintf(fullFilename, sizeof(fullFilename), "%s.csv", filename);
    } else {
        // If it already contains ".csv", use the provided filename
        snprintf(fullFilename, sizeof(fullFilename), "%s", filename);
    }

    file = fopen(fullFilename, "w"); // Open file in write mode

    if (file == NULL) {
        printf("Unable to create the file.\n");
        return;
    }

    // Write data to the file in CSV format
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fprintf(file, "%s", data[i][j]);
            if (j != MAX_COLS - 1) {
                fprintf(file, ",");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Data exported to '%s' successfully.\n", filename);
}

//2d


// Example usage in main()
int main() {
    // Sample data
    FILE *fp = fopen("file.csv", "r");
    char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];  // Store CSV data
    char buffer[1024];  // Buffer to read each line from the file
    char exportName[150];
    int row = 0;

    // ... (Previous code for reading and processing data)

        // Read data from file
    while (fgets(buffer, sizeof(buffer), fp) != NULL && row < MAX_ROWS) {
        int col = 0;
        char *token = strtok(buffer, ",\n");  //hilangkan ,

        while (token != NULL && col < MAX_COLS) {
            strcpy(data[row][col], token);  //disimpan diaalam data
            token = strtok(NULL, ",\n");
            col++;
        }

        row++;
    }

    // Export data to a new CSV file
    char exportFilename[50]; // Store the user-specified filename
    printf("Enter the filename to export (including .csv extension): ");
    scanf("%s", exportFilename);

    exportToCSV(data, row, exportFilename); // Call the export function with the filename

    return 0;
}
