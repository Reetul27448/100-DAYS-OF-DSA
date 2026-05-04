#include <stdio.h>
#include <string.h>
#define MAX 100
int main() {
    int n;
    char candidates[MAX][MAX];
    int voteCount[MAX] = {0};

    printf("Enter the number of votes: ");
    scanf("%d", &n);

    printf("Enter the candidate names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", candidates[i]);
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (strcmp(candidates[i], candidates[j]) == 0) {
                voteCount[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            voteCount[i]++;
        }
    }

    char winner[MAX];
    int maxVotes = 0;

    for (int i = 0; i < n; i++) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            strcpy(winner, candidates[i]);
        } else if (voteCount[i] == maxVotes && strcmp(candidates[i], winner) < 0) {
            strcpy(winner, candidates[i]);
        }
    }

    printf("%s %d\n", winner, maxVotes);
    
    return 0;
}
