#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char buffer[1000];
    FILE *fp = fopen("file.csv", "r");
    int ch = getc(fp);
    int row = 0;

    // while ()
    // {
    //     printf("%s", buffer);
    //     row++;
    // }
    
    fclose(fp);
}