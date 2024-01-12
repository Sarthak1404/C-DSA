// Insertion sort
#include <stdio.h>
void insertionSort(int arr[], int n) {
  int i, j, key;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    // Compare key with each element on the left of it until an element smaller than it is found
    // For descending order, change key<arr[j] to key>arr[j].
    while (j >= 0 && key < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    // Place key at after the element just smaller than it.
    arr[j + 1] = key;
  }
}

int main() {
  int arr[100], n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the array elements: ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  insertionSort(arr, n);
  printf("Sorted array: \n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
