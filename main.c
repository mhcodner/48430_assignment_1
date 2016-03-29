#include <stdio.h>
#include <string.h>


int triangularNumber (int n) {
    return n * (n + 1) / 2;
}

int printEvenTriangle (int size) {
    int highest = 1; // Store the highest even number
    for (int i = 1; i < size; i++) {
        int triangle = triangularNumber(i); // Get triangle number for current iteration
        if (triangle % 2 == 0 && triangle < size) { // Check if the triangle number is even and less than the input
            printf("\t%d", triangle);
            highest = triangle;
        }
    }
    printf("\n");
    return highest;
}

void printTriangle (int size) {
    for (int i = 1; i < size; i++) {
        int triangle = triangularNumber(i); // Get triangle number for current iteration
        char pad[128]; // The string used to left pad the output
        if (triangle < size) {
            printf("%s%02d \n", pad, triangle);
            strcat(pad, "** "); // Add '** ' to the string in each iteration
        }
    }
}

int main() {
    int size;
    printf("Enter a number between 0 and 200>");
    scanf("%d", &size); // Receive input and store in the 'size' integer
    printf("Printing even triangular numbers below %d:\n", size);
    int highest = printEvenTriangle(size); // Print the even triangle numbers and store the highest number
    printf("The last even triangular number is %d. Printing the triangle:\n", highest);
    printTriangle(size); // Print the whole triangle
    return 0;
}