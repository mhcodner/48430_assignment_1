/**********************************************************************
48430 Embedded C - Assignment 1
Name: Michael Codner
Student ID: 11989668
Date of submission: 05/04/2016
A brief statement on what you could achieve (less than 50 words):
Everything

A brief statement on what you could NOT achieve (less than 50 words):
Nothing

**********************************************************************/

/**********************************************************************
List of header files - do NOT use any other header files.
**********************************************************************/
#include<stdio.h>

/**********************************************************************
Function prototypes - do NOT change the given prototypes. However you
may define your own functions if required.
**********************************************************************/
char isOdd(int);

/* Check if an integer is odd */
char isTriangle(int);

/* Check if an integer is a triangular number */
void printTriangle(int);

/* Print a triangle corresponding to an int */
int printEvenTriangle(int);


/**********************************************************************
Main
**********************************************************************/
int main(void) {
    int size;
    printf("Enter a number between 0 and 200>");
    scanf("%d", &size); /* Receive input and store in the 'size' integer */
    printf("Printing even triangular numbers below %d:\n", size);
    int highest = printEvenTriangle(size); /* Print the even triangle numbers and store the highest number */
    printf("The last even triangular number is %d. Printing the triangle:\n", highest);
    printTriangle(size); /* Print the whole triangle */
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
    int currentTriNum = 0;
    int n = 0;

    while (currentTriNum < input) {
        currentTriNum += n;
        n++;
    }

    if (currentTriNum != input) {
        return 0;
    }
    else {
        return 1;
    }
}

/**********************************************************************
Prints the even triangle numbers
returns the highest even number
**********************************************************************/
int printEvenTriangle(int size) {
    int highest = 1; /* Store the highest even number */
    int i;
    for (i = 1; i <= size; i++) {
        if (!isOdd(i) && isTriangle(i)) { /* Check if the number is even and triangular */
            printf("   %d", i);
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
    for (i = 1; i <= size; i++) {
        if (isTriangle(i)) {
            int n;
            for (n = 1; n < count; n++) {
                printf("** "); /* Print the right number of *'s */
            }
            printf("%02d \n", i); /* Print the number padded with zeros */
            count++;
        }
    }
}
