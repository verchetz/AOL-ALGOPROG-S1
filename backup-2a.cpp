#include <stdio.h>
#include <string.h>
#include <string.h>

#define MAX_ROWS 5000
#define MAX_COLS 50
#define MAX_FIELD_LENGTH 200

//2a
void display(FILE *fp, int row){
    int limit;
    char line[MAX_COLS][MAX_FIELD_LENGTH];
    char buffer[1024]; //store data
    printf("Number of rows: ");
    scanf("%d", &limit); getchar();

        //tampilkan data
    while (fgets(buffer, sizeof(buffer), fp) != NULL && row < limit+1) {
        int col = 0;
        char *token = strtok(buffer, ",\n"); // hilangkan ","

        while (token != NULL && col < MAX_COLS) {
            strcpy(line[col], token); // Store each field in line[col]
			
            //bagusin tampilan dengan strlen
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
    } while (userInput < 1 || userInput > 6);
    
    
    if (userInput == 1)
    {
        display(fp, row);
    }
    


    fclose(fp);
    return 0;
}
