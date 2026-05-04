#include <stdio.h>
#define MAX 100
char firstNonRepeatingCharacter(char str[]) {
    int count[26] = {0}; // Assuming only lowercase letters

    // Count the frequency of each character
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
    }

    // Find the first non-repeating character
    for (int i = 0; str[i] != '\0'; i++) {
        if (count[str[i] - 'a'] == 1) {
            return str[i];
        }
    }

    return '$'; // Return '$' if all characters repeat
}
int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    char result = firstNonRepeatingCharacter(str);
    printf("First non-repeating character: %c\n", result);

    return 0;
}
