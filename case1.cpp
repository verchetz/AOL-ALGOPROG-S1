#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inverse(char *str) {
    int i = 0;

    //selama bukan null
    while (str[i] != '\0') {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]); //to lowercase
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]); //to uppercases
        }
        i++;
    }
}

int main() {
    char text[111];

    //input
    printf("masukan string: ");
    scanf("%[^\n]s", &text);
    
    inverse(text);
    
    //output
    printf("%s\n", strrev(text));
    
    return 0;
}
