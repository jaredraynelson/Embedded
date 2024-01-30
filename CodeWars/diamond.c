#include <stdlib.h>

char *diamond (int n) {

  
    if (n>0 && n%2==1) {
      // allocate a string on the heap, memory will be freed
      int tSpaces = 0;
      for (int s=((n+2)/2)+1; s<(n+1); s++) {
        tSpaces += 2*s;
      }

      tSpaces += (n+1);
      char* d = calloc(tSpaces+1, sizeof(char));
      d[tSpaces] = '\0';

      // VARIABLE SETUP
      int ws = n/2;
      int stars = 1;
      int incD = 0;

      // BUILD TOP PART OF DIAMOND
      while (ws>0) {
        for (int i=0; i<ws; i++) {
          d[incD++] = ' ';
        }
        for(int i=0; i<stars; i++) {
          d[incD++] = '*';
        }
        d[incD++] = '\n';
        stars += 2;
        ws--;
      }
      
      // BUILD THE MIDDLE OF THE DIAMOND     
      for (int i=0; i<n; i++) {
        d[incD++] = '*';
      }
      d[incD++] = '\n';

      // BUILD THE END OF THE DIAMOND
      stars -= 2;
      ws++;
      while (stars > 0) {
        for(int i=0; i<ws; i++) {
          d[incD++] = ' ';
        }
      for (int i=0; i<stars; i++) {
          d[incD++] = '*';
      }
        stars -= 2;
        ws++;
        d[incD++] = '\n';
    }
    return d;
  }
  return NULL;
}
