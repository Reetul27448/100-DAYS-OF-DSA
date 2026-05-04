#include <stdio.h>
#define MAX 100
int hashTable[MAX];
int hashFunction(int key, int i) {
    return (key + i * i) % MAX;
}
void insert(int key) {
    int i = 0;
    int index;
    while (i < MAX) {
        index = hashFunction(key, i);
        if (hashTable[index] == 0) { // Empty slot
            hashTable[index] = key;
            return;
        }
        i++;
    }
}
int search(int key) {
    int i = 0;
    int index;
    while (i < MAX) {
        index = hashFunction(key, i);
        if (hashTable[index] == key) {
            return 1; // Found
        }
        if (hashTable[index] == 0) { // Empty slot, not found
            return 0;
        }
        i++;
    }
    return 0; // Not found after probing entire table
}
int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char operation[10];
        int key;
        printf("Enter operation (INSERT/SEARCH) and key: ");
        scanf("%s %d", operation, &key);
        
        if (operation[0] == 'I') { // INSERT
            insert(key);
        } else if (operation[0] == 'S') { // SEARCH
            if (search(key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    
    return 0;
}
