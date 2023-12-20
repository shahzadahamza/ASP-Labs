#include <stdio.h>
#include <stdlib.h>

int main() {
    int size, i;
    int* dynamicArray;

    printf("Press the number in the array: ");
    scanf("%d", &size);
    dynamicArray = (int*)malloc(size * sizeof(int));
printf("Press the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", dynamicArray + i);
    }
    printf("Reversing Order:\n");
    for (i = size - 1; i >= 0; i--) {
        printf("%d\n", *(dynamicArray + i));
    }
    free(dynamicArray);
    return 0;
}