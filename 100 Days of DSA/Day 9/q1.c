#include <stdio.h>
#include <string.h>
#define MAX 100
void mirrorString(char str[]) {
    int length = strlen(str);
    char mirrored[MAX];

    for (int i = 0; i < length; i++) {
        mirrored[i] = str[length - 1 - i];
    }
    mirrored[length] = '\0'; // Null-terminate the mirrored string

    printf("%s\n", mirrored);
}
int main() {
    char codeName[MAX];

    printf("Enter the code name: ");
    scanf("%s", codeName);

    mirrorString(codeName);

    return 0;
}