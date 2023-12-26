#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 4000
#define MAX_COLS 8
#define MAX_FIELD_LENGTH 50

//for 2a and 2b, selection for column
int columnIdentifier(char column[]){
    if (strcasecmp(column, "location") == 0)
    {
        return 0;
    }else if (strcasecmp(column, "city") == 0)
    {
        return 1;
    }else if (strcasecmp(column, "price") == 0)
    {
        return 2;
    }else if (strcasecmp(column, "rooms") == 0)
    {
        return 3;
    }else if (strcasecmp(column, "bathrooms") == 0)
    {
        return 4;
    }else if (strcasecmp(column, "carparks") == 0)
    {
        return 5;
    }else if (strcasecmp(column, "type") == 0)
    {
        return 6;
    }else if (strcasecmp(column, "city") == 0)
    {
        return 7;
    }
}


//2a
void display(FILE *fp) {
    char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];  // Store CSV data
    char buffer[1024];  // Buffer to read each line from the file

    // Read data from file
    int row = 0;
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

    //tanya may tampilin berapa banyak
    int limit = 0;
    printf("Jumlah row: ");
    scanf("%d", &limit); getchar();
    //table
    for (int i = 0; i < limit+1; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%-24s", data[i][j]);
        }
        printf("\n");
    }
}

//2b
void search(FILE *fp){
    char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];  // Store CSV data
    char buffer[1024];  // Buffer to read each line from the file

        // dibaca dulu
    int row = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && row < MAX_ROWS) {
        int col = 0;
        char *token = strtok(buffer, ",\n");  // Split the line into tokens using ',' or newline

        while (token != NULL && col < MAX_COLS) {
            strcpy(data[row][col], token);  // Store each field in data[row][col]
            token = strtok(NULL, ",\n");
            col++;
        }

        row++;
    }

    //specific value
    int colIdentifier;
    char key[MAX_FIELD_LENGTH], column[1024];
    printf("Choose Column: ");
    scanf("%s", column);getchar();
    printf("Key to find: ");
    scanf("%s", key); getchar();

    colIdentifier = columnIdentifier(column);

        // Display rows containing the search value
    int found = 0;
    printf("%-23s %-23s %-23s %-23s %-23s %-23s %-23s %-23s\n", "Location 1", "Location 2", "Price","Rooms","Bathrooms","CarParks","Type","Furnish");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (strcasecmp(data[i][colIdentifier], key) == 0) {
                found = 1;
                for (int k = 0; k < MAX_COLS; k++) {
                    printf("%-24s", data[i][k]);  // Print the entire row
                }
                printf("\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Value not found in the table.\n");
    }
}

//2c
void sort(FILE *fp){
    char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];  // Store CSV data
    char buffer[1024];  // Buffer to read each line from the file

    // dibaca dulu
    int row = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && row < MAX_ROWS) {
        int col = 0;
        char *token = strtok(buffer, ",\n");  // Split the line into tokens using ',' or newline

        while (token != NULL && col < MAX_COLS) {
            strcpy(data[row][col], token);  // Store each field in data[row][col]
            token = strtok(NULL, ",\n");
            col++;
        }

        row++;
    }

        //specific value
    int colIdentifier;
    char order[MAX_FIELD_LENGTH], column[1024];
    printf("Choose Column: ");
    scanf("%s", column);getchar();
    printf("Asc or desc? ");
    scanf("%s", order); getchar();

    colIdentifier = columnIdentifier(column);

}

int main() {
    FILE *fp;
    int userInput;
    fp = fopen("file.csv", "r");  // Replace "data.csv" with your file name

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    //menu
    do
    {
        puts("What do you want to do?");
        puts("1. Display data");
        puts("2. Search data");
        puts("3. Sort data");
        puts("4. Export data");
        puts("5. Exit");
        printf("Your Choice: ");
        scanf("%d", &userInput);getchar();
    } while (userInput < 0 || userInput > 6);
    
        //selection
    switch (userInput)
    {
        case 1:
            rewind(fp);
            display(fp);
            break;
        case 2:
            rewind(fp);
            search(fp);
            break;
        case 3:
            rewind(fp);
            sort(fp);
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
    }
    


    fclose(fp);
    return 0;
}
