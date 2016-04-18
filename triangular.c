/**********************************************************************
48430 Embedded C - Assignment 1
Name: Michael Codner
Student ID: 11989668
Date of submission: 11/04/2016
A brief statement on what you could achieve (less than 50 words):
Everything

A brief statement on what you could NOT achieve (less than 50 words):
Nothing

**********************************************************************/

/**********************************************************************
List of header files - do NOT use any other header files.
**********************************************************************/
#include <stdio.h>

/**********************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
**********************************************************************/

/* Check if an integer is odd */
char isOdd(int);

/* Check if an integer is a triangular number */
char isTriangle(int);

/* Print a triangle corresponding to an int */
void printTriangle(int);

/* Prints the even triangular numbers <= the input */
int printEvenTriangle(int);


/**********************************************************************
Main
**********************************************************************/
int main(void) {
    int size;
    printf("Enter a number between 0 and 200>");
    scanf("%d", &size); /* Receive input and store in the 'size' integer */
    printf("Printing even triangular numbers below %d:\n", size);
    if (size >= 6) { /* Solution only prints numbers >= 6 */
        int highest = printEvenTriangle(size); /* Print the even triangle numbers and store the highest number */
        printf("The last even triangular number is %d. Printing the triangle:\n", highest);
        printTriangle(highest); /* Print the whole triangle up to the highest even number */
    }
    return 0;
}


/**********************************************************************
Check if an integer n is odd.
return 1 - if odd
return 0 - otherwise
**********************************************************************/
char isOdd(int n) {
    return n % 2 == 1;
}

/**********************************************************************
Check if an integer n is a triangular number.
return 1 - if n is triangular
return 0 - if n is not triangular
**********************************************************************/
char isTriangle(int input) {
    int currentTriNum = 0, n = 0; /* n is used as loop index,
                                   * currentTriNum is used as the current triangular number for the loop index  */

    while (currentTriNum < input) {
        currentTriNum += n; /* Triangular numbers are the sum from 1 to n */
        n++;
    }

    return currentTriNum == input; /* The input is triangular if it is equal to the currentTriNum */
}

/**********************************************************************
Prints the even triangle numbers
returns the highest even number
**********************************************************************/
int printEvenTriangle(int size) {
    int highest = 0; /* Store the highest even number, default is 1 because that is the lowest triangular number */
    int i;
    for (i = 1; i <= size; i++) {
        if (!isOdd(i) && isTriangle(i)) { /* Check if the number is even and triangular */
            if (i < 100) {
                printf("   %d", i); /* Print the even triangular number left-padded with 3 spaces */
            }
            else {
                printf("  %d", i); /* Print the even triangular number left-padded with 3 spaces */
            }
            highest = i; /* Update highest even number */
        }
    }
    printf(" \n");
    return highest;
}

/**********************************************************************
Print all triangular numbers below n along the hypotenuse of a triangle
shape. e.g. 10 is a triangular number, therefore the function prints
01
** 03
** ** 06
** ** ** 10
**********************************************************************/
void printTriangle(int size) {
    int i;
    int count = 1; /* Used to count the number of *'s */
    for (i = 1; i <= size; i++) { /* loop from 1 to the input number */
        if (isTriangle(i)) { /* Check if current iteration is a triangular number */
            int n;
            for (n = 1; n < count; n++) {
                printf("** "); /* Print the right number of *'s */
            }
            printf("%02d \n", i); /* Print the number padded with zeros */
            count++;
        }
    }
}
