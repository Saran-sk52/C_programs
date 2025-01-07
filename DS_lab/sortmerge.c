#include <stdio.h>
void insert_elements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge_arrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        merged[k++] = arr1[i++];
    }
    while (j < size2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    
    int array1[size1];
    insert_elements(array1, size1);
    printf("The unsorted 1st array is:");
    for(int i = 0 ; i < size1 ; i++) {
    	printf(" %d ", array1[i]);
    	}
    sort_array(array1, size1);
    printf("\nThe sorted array is:");
    for(int i = 0 ; i < size1 ; i++) {
    	printf(" %d ", array1[i]);
    	}
    printf("\nEnter the size of the second array: ");
    scanf("%d", &size2);
    
    int array2[size2];
    insert_elements(array2, size2);
    printf("The unsorted 2nd array is:");
    for(int i = 0 ; i < size2 ; i++) {
    	printf(" %d ",array2[i]);
    	}
    sort_array(array2, size2);
    printf("\nThe sorted array is:");
    for(int i = 0 ; i < size1 ; i++) {
    	printf(" %d ", array2[i]);
    	}
    
    int merged[size1 + size2];
    merge_arrays(array1, size1, array2, size2, merged);
    printf("\nSorted merged array:");
    for (int i = 0; i < size1 + size2; i++) {
        printf(" %d ", merged[i]);
    } /*   
    sort_array(merged, size1 + size2);
    printf("\nSorted merged array: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }*/
    printf("\n");

    return 0;
}
