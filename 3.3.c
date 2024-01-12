#include <stdio.h>
void swap(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}
int main() {
  int arr[100], n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the array elements: ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  bubbleSort(arr, n);
  printf("Sorted array: \n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
