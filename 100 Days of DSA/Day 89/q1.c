/*
Problem Statement
Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).
*/
#include <stdio.h>
#define MAX 1000

int findMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

int sum(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int isFeasible(int arr[], int n, int m, int mid) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid)
            return 0;

        if (pages + arr[i] > mid) {
            students++;
            pages = arr[i];

            if (students > m)
                return 0;
        } else {
            pages += arr[i];
        }
    }
    return 1;
}

int findMinimumPages(int arr[], int n, int m) {
    int low = findMax(arr, n);
    int high = sum(arr, n);

    while (low < high) {
        int mid = (low + high) / 2;

        if (isFeasible(arr, n, m, mid))
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n, m;
    int arr[MAX];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (m > n) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", findMinimumPages(arr, n, m));

    return 0;
}