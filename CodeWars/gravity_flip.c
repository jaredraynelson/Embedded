#include <stddef.h>
#include <stdlib.h>

//  do not allocate memory for the return value
//  assign output to preallocated array *result

int cmp (const void * a, const void * b) {
  if ((*(const int *) a) > (*(const int *) b) ) { return 1; }
  else if ((*(const int *) a) == (*(const int *) b)) { return 0; }
  else { return -1; }
}

int rev_cmp (const void * a, const void * b) {
  if ((*(const int *) a) > (*(const int *) b) ) { return -1; }
  else if ((*(const int *) a) == (*(const int *) b)) { return 0; }
  else { return 1; }
}

void flip(char d, const int *array, size_t n, int *result) {

  //   IF GRAVITY IS RIGHT, IT'S A SORTED ARRAY SMALLEST TO LARGEST
  if (d == 'R') { qsort((void *) array, n, sizeof(int), cmp); }
  //   IF GRAVITY IS LEFT, IT'S A SORTED ARRAY LARGEST TO SMALLEST
  if (d == 'L') { qsort((void *) array, n, sizeof(int), rev_cmp); }
  
  //   MUST USE MEMCPY B/C WE LOOK TO COPY THE EXACT RESULTS INTO THE ARRAY.
  memcpy(result, array, n * sizeof(int));
  
}
