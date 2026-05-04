#include <stdio.h>
#define MAX 100
typedef struct {
    int position;
    int speed;
} Car;
int compare(const void *a, const void *b) {
    Car *carA = (Car *)a;
    Car *carB = (Car *)b;
    return carB->position - carA->position; // Sort in descending order
}
int carFleet(int target, Car cars[], int n) {
    qsort(cars, n, sizeof(Car), compare);
    int fleets = 0;
    double timeToReach[MAX];

    for (int i = 0; i < n; i++) {
        timeToReach[i] = (double)(target - cars[i].position) / cars[i].speed;
    }

    double currentFleetTime = 0.0;
    for (int i = 0; i < n; i++) {
        if (timeToReach[i] > currentFleetTime) {
            fleets++;
            currentFleetTime = timeToReach[i];
        }
    }
    return fleets;
}
int main() {
    int target, n;

    printf("Enter the target distance: ");
    scanf("%d", &target);

    printf("Enter the number of cars: ");
    scanf("%d", &n);

    Car cars[MAX];
    printf("Enter the position and speed of each car (position speed):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cars[i].position, &cars[i].speed);
    }

    int result = carFleet(target, cars, n);
    printf("Number of car fleets that will arrive at the destination: %d\n", result);

    return 0;
}
