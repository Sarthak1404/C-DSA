#include <stdio.h>
void swap(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;
    swap(&arr[min_idx], &arr[i]);
  }
}
int main() {
  int arr[100], n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the array elements: ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  selectionSort(arr, n);
  printf("Sorted array: \n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
