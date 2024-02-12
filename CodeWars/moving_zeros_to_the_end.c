/*
Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.

move_zeros(10, int [] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1}); // -> int [] {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}
*/

#include <stddef.h>


void move_zeros(size_t len, int arr[len])
{
    
  for (size_t i=0; i<len; i++) {
    int n = arr[i];
    if (n == 0) {
    // WE'RE GOING THROUGH THE ARRAY TO THE END
    size_t k = i+1;
    size_t ptr = i;

    while(n == 0 && k < len) {
      int m = arr[k];
      if (m != 0) {
        int tmp = arr[k];
        // ZERO IN PLACE OF arr[k]
        arr[k] = arr[ptr];
        // ORIGINAL arr[ptr] swapped with non-zero element
        arr[ptr] = tmp;
        ptr = k;
        n = arr[ptr];
      }
      k++;
    }
    }
    }
}
