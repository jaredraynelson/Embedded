#include <stddef.h>

int cmp (const int * a, const int * b) {
  int vA = *(const int *) a;
  int vB = *(const int *) b;
  
  if (vA>vB) { return 1; }
  else if (vA==vB) { return 0; }
  else { return -1; }
  
}

long sum_two_smallest_numbers(size_t n, const int numbers[n]) {

    //  <----  hajime!
    qsort((void *) numbers, n, sizeof(int), cmp);
  
    long vA = (long) numbers[0];
    long vB = (long) numbers[1];

    return vA + vB;
}
