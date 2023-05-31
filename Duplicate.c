//Code to identify the number of duplicate elements in an array & print the number of times the duplicate element is existing

#include <stdio.h>
int main() {
    int size, i;

    printf("Enter the size of array:\n ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    duplicate(arr, size);

    return 0;
}


void duplicate(int arr[], int size) {
    int i, j, count;


    for (i = 0; i < size; i++) {
        count = 1;


        if (arr[i] == -1)
            continue;


        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                arr[j] = -1;
            }
        }


        if (count > 1)
            printf("Number %d occurs %d times.\n", arr[i], count);
    }
}
