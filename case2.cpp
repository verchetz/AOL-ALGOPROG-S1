#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 5000
#define MAX_COLS 50
#define MAX_FIELD_LENGTH 900

//2a
void display(FILE *fp) {
    int limit = 0;
    char data[MAX_ROWS][MAX_COLS][MAX_FIELD_LENGTH];  // Store CSV data
    char buffer[1024];  // Buffer to read each line from the file

    //tanya may tampilin berapa banyak
    printf("Jumlah row: ");
    scanf("%d", &limit); getchar();

    // Read data from file
    int row = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && row < limit+1) {
        int col = 0; 
        char *token = strtok(buffer, ",\n");  // Split the line into tokens using ',' or newline

        while (token != NULL && col < MAX_COLS) {
            strcpy(data[row][col], token);  // Store each field in data[row][col]
            token = strtok(NULL, ",\n");
            col++;
        }

        row++;
    }

    //table
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%-23s", data[i][j]);  // Adjust width as needed for columns
        }
        printf("\n");
    }
}

//2b search
void search(FILE *fp){
    char column[150], key[150];
    char line[MAX_COLS][MAX_FIELD_LENGTH];
    char buffer[1024]; //store data
    int currentLine = 1;
    printf("Choose column: ");
    scanf("%[^\n]s", &column); getchar();
    printf("What do you want to find: ");
    scanf("%[^\n]s", &key); getchar();

        //tampilkan data
    int row = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL && row < 10) {
        int col = 0;
        char *token = strtok(buffer, ",\n"); // hilangkan ","
        
        while (token != NULL && col < MAX_COLS) {
            strcpy(line[col], token); // Store each field in line[col]
			
            //bagusin tampilan dengan strlen
            if (strcmp(token, key) == 0)
            {                
                if (strlen(line[col]) < 8 || strlen(line[col]) == 0)
                {                
                    printf("%s\t\t\t", line[col]); // Display each field (tab-separated)
                }else if (8 <= strlen(line[col]) && strlen(line[col]) < 15)
                {
                    printf("%s\t\t", line[col]);
                }else if (strlen(line[col]) >= 15)
                {
                    printf("%s\t", line[col]);
                }
            }else{
                printf("not found!");
            }
            
            token = strtok(NULL, ",\n");
            col++;
        }

        printf("\n"); // Move to the next line for the next row
        row++;
    }
}

int main() {
    FILE *fp;
    fp = fopen("file.csv", "r");
    int row = 0;
    int userInput = 0;

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
            search(fp);
            break;
        case 3:
            printf("Wednesday");
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
