#include <stdio.h>
#define MAX 100
char firstRepeatedCharacter(char str[]) {
    int count[26] = {0}; // Assuming only lowercase letters

    // Count the frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
        if (count[str[i] - 'a'] == 2) {
            return str[i]; // Return the first repeated character
        }
    }

    return -1; // Return -1 if no character is repeated
}
int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstRepeatedCharacter(str);
    if (result != -1) {
        printf("First repeated character: %c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}
