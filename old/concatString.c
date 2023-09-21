#include <stdio.h>
#include <string.h>

void concatenateStrings(char result[], const char str1[], const char str2[]) {
    strcpy(result, str1);     // Copy the first string to the result
    strcat(result, str2);     // Concatenate the second string to the result
}

int main() {
    char string1[100];
    char string2[100];
    char concatenated[200];

    printf("Enter the first string: ");
    scanf("%s", string1);

    printf("Enter the second string: ");
    scanf("%s", string2);

    concatenateStrings(concatenated, string1, string2);

    printf("Concatenated string: %s\n", concatenated);

    return 0;
}
