#include <stdio.h>
#include <string.h>


int triangularNumber (int n) {
    return n * (n + 1) / 2;
}

int printEvenTriangle (int size) {
    int highest = 1;
    for (int i = 1; i < size; i++) {
        int triangle = triangularNumber(i);
        if (triangle % 2 == 0 && triangle < size) {
            printf("\t%d", triangle);
            highest = triangle;
        }
    }
    printf("\n");
    return highest;
}

void printTriangle (int size) {
    for (int i = 1; i < size; i++) {
        int triangle = triangularNumber(i);
        char pad[128];
        if (triangle < size) {
            printf("%s%02d \n", pad, triangle);
            strcat(pad, "** ");
        }
    }
}

int main() {
    int size;
    printf("Enter a number between 0 and 200>");
    scanf("%d", &size);
    printf("Printing even triangular numbers below %d:\n", size);
    int highest = printEvenTriangle(size);
    printf("The last even triangular number is %d. Printing the triangle:\n", highest);
    printTriangle(size);
    return 0;
}