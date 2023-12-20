#include <stdio.h>
#include <stdlib.h>

int smallest2(int *n1, int *n2, int *n3, int *n4) {
    int smallest = *n1;
    int secondSmallest = *n2;

    if (*n1 > *n2) {
        smallest = *n2;
        secondSmallest = *n1;
    }

    if (*n3 < smallest) {
        secondSmallest = smallest;
        smallest = *n3;
    } else if (*n3 < secondSmallest) {
        secondSmallest = *n3;
    }

    if (*n4 < smallest) {
        secondSmallest = smallest;
        smallest = *n4;
    } else if (*n4 < secondSmallest) {
        secondSmallest = *n4;
    }

    return secondSmallest;
}

int largest2(int *n1, int *n2, int *n3, int *n4) {
    int largest = *n1;
    int secondLargest = *n2;

    if (*n1 < *n2) {
        largest = *n2;
        secondLargest = *n1;
    }

    if (*n3 > largest) {
        secondLargest = largest;
        largest = *n3;
    } else if (*n3 > secondLargest) {
        secondLargest = *n3;
    }

    if (*n4 > largest) {
        secondLargest = largest;
        largest = *n4;
    } else if (*n4 > secondLargest) {
        secondLargest = *n4;
    }

    return secondLargest;
}

int difference(int smallest2, int largest2, int *n1, int *n2, int *n3, int *n4) {
    return largest2 - smallest2;
}

int main() {
    int num1, num2, num3, num4;
    num1 = 10;
    num2 = 30;
    num3 = 20;
    num4 = 15;

    int secondSmallest = smallest2(&num1, &num2, &num3, &num4);
    int secondLargest = largest2(&num1, &num2, &num3, &num4);
    int result = difference(secondSmallest, secondLargest, &num1, &num2, &num3, &num4);

    printf("Second smallest number is: %d\n", secondSmallest);    printf("Second largest number is: %d\n", secondLargest);    printf("Difference of the Second largest and Second smallest numbers: %d\n", result);
    return 0;
}

