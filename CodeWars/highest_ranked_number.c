#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>


int compare_ints(const void *a, const void *b) {
    int valA = *(const int *)a;
    int valB = *(const int *)b;

    if (valA < valB) {
        return -1;
    } else if (valA > valB) {
        return 1;
    } else {
        return 0;
    }
}

int get_most_frequent (size_t length, const int array[length]) {  
  
  qsort(array, length, sizeof(int), compare_ints);
  
  int numOcc = 1;
  int highOcc = 1;
  int rNum = array[0];
  
  for (size_t i=0; i<length; i++) {
    if (array[i] == array[i+1]) {
      numOcc++;
    }
    else {
      if (numOcc >= highOcc) {
        if (array[i] > rNum) {rNum = array[i];}
        highOcc = numOcc;
        }
      numOcc=1;
    }
  }
	return rNum;
}
