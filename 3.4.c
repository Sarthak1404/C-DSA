#include <stdio.h>
void swap(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // choose the last element as pivot
  int i = low - 1; // index of smaller element
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) { // if current element is smaller than pivot
      i++; // increment index of smaller element
      swap(&arr[i], &arr[j]); // swap it with the element at i
    }
  }
  swap(&arr[i + 1], &arr[high]); // swap the pivot element with the element at i+1
  return i + 1; // return the partition index
}
void quickSort(int arr[], int low, int high) {
  if (low < high) { // base case
    int pi = partition(arr, low, high); // get the partition index
    quickSort(arr, low, pi - 1); // sort the left subarray
    quickSort(arr, pi + 1, high); // sort the right subarray
  }
}
int main() {
  int arr[100], n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  printf("Enter the array elements: ");
  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  quickSort(arr, 0, n - 1); // call quick sort function
  printf("Sorted array: \n");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
  return 0;
}
