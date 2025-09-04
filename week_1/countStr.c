#include <stdio.h>

int main() {
    char str[100];
    int i = 0, words = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if ((str[i] != ' ' && str[i] != '\n') && 
            (i == 0 || str[i-1] == ' ')) {
            words++;
        }
        i++;
    }

    printf("Number of words = %d\n", words);

    return 0;
}
