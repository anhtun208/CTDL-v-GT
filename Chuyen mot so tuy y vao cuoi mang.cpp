#include <stdio.h>
void push_to_end(int arr[], int n, int t) {
  // Kh?i t?o hai bi?n ch? s? i và j
  int i = 0; // Ch? s? cho ph?n t? hi?n t?i
  int j = n - 1; // Ch? s? cho ph?n t? cu?i cùng
  // L?p qua m?ng t? d?u d?n cu?i
  while (i < j) {
    // N?u ph?n t? hi?n t?i b?ng t
    if (arr[i] == t) {
      // Ð?i ch? nó v?i ph?n t? cu?i cùng
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      // Gi?m j di m?t don v?
      j--;
    }
    else {
      // Tang i lên m?t don v?
      i++;
    }
  }
}

// Hàm d? in ra m?ng
void print_array(int arr[], int n) {
  // L?p qua m?ng và in ra t?ng ph?n t?
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Ví d?
int main() {
  int arr[] = {0,3,0,5,4,7,9,0,1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int t = 0;
  push_to_end(arr, n, t);
  print_array(arr, n);
  // K?t qu?: 3 5 4 7 9 1 0 0 0 
}
