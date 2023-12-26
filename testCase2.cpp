#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 4000
#define MAX_COLS 8
#define MAX_FIELD_LENGTH 50

//for 2b and 2c, selection for column
int columnIdentifier(){
    char column[1024];
    printf("Choose Column: ");
    scanf("%s", column);getchar();

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
void display(FILE *fp, char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH]) {
    //how many data will be displayed
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
void search(FILE *fp, char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH], int row){
    //specific value
    int colIdentifier = columnIdentifier();
    char key[MAX_FIELD_LENGTH];
    printf("Key to find: ");
    scanf("%s", key); getchar();

    //Display rows containing the search value
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
void sort(FILE *fp, char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH], int row){
    int colIdentifier = columnIdentifier();
    char order[MAX_FIELD_LENGTH];
    
    printf("Asc or desc? ");
    scanf("%s", order); getchar();

    if (colIdentifier == 2 || colIdentifier == 3 || colIdentifier == 4)
    {        
        for (int i = 1; i < row - 1; i++)
        {
            for (int j = 1; j < MAX_COLS; j++)
            {
                int val1 = atoi(data[i][colIdentifier]);
                int val2 = atoi(data[j][colIdentifier]);
                //sorting
                if ((strcasecmp(order, "asc") == 0 && val1 < val2) || (strcasecmp(order, "desc") == 0 && val1 > val2))
                {
                    for (int k = 0; k < MAX_COLS; k++) {
                        char temp[MAX_FIELD_LENGTH];
                        strcpy(temp, data[i][k]);
                        strcpy(data[i][k], data[j][k]);
                        strcpy(data[j][k], temp);
                    }
                }
            }
        }

        //jika sudah di sort, lanjut looping
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                printf("%-25s", data[i][j]);
            }
            printf("\n");
        }

    }else{
        printf("only sort integer\n");
    }
    
}

//2d
void exportFile(char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH], int row){
    char newFileName[150];
    printf("File name: ");
    scanf("%s", newFileName);

    //create new file with name based on user input
    FILE *newFile;
    char validFileName[150];

    //check if theres .csv format or not
    if (strstr(newFileName, ".csv") == NULL) //if theres no .csv extension, then append it
    {
        snprintf(validFileName, sizeof(validFileName), "%s.csv", newFileName);
    }else{
        snprintf(validFileName, sizeof(validFileName), "%s", newFileName);
    }

    newFile = fopen(validFileName, "w");

    if (newFileName == NULL)
    {
        printf("unable to create file!\n");
        return;
    }
    
    // Write data to the file in CSV format
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            fprintf(newFile, "%s", data[i][j]);
            if (j != MAX_COLS - 1) {
                fprintf(newFile, ",");
            }
        }
        fprintf(newFile, "\n");
    }

    fclose(newFile);
    printf("Data successfully written to file %s.csv", newFileName);
}

int main() {
    FILE *fp;
    fp = fopen("file.csv", "r");
    int userInput;
    char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];  //array to store CSV data
    char buffer[1024];  // Buffer to read each line from the file
    int row = 0;

    if (fp == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

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
            display(fp, data);
            break;
        case 2:
            rewind(fp);
            search(fp, data, row);
            break;
        case 3:
            rewind(fp);
            sort(fp, data, row);
            break;
        case 4:
            rewind(fp);
            exportFile(data, row);
            break;
        case 5:
            printf("Friday");
            break;
    }
    


    fclose(fp);
    return 0;
}
