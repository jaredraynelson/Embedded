#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// Without STRNCAT & exact memory allocation.
// char *smash (const char *const words[/* count */], size_t count)
// {
// // allocate a string on the heap, memory will be freed
//   int size=0;
//   char * word;
//   for (int i=0; i<(int)count; i++) {
//     word = (char *) words[i];
//     size += (int)strlen(word);
//   }
//   char* rStr = (char*) calloc((size+count), sizeof(char*));
//   int k = 0;
//   for (int i=0; i<count; i++) {
//     word = (char *) words[i];
//     for (int j=0; j<strlen(word); j++) {
//       rStr[k] = word[j];
//       k++;
//     }
//     if (i+1 < count) {
//       rStr[k] = ' ';
//       k++;
//     }
//   }
//   printf("%s\n", rStr);
// 	return rStr;
// }

// Faster, but dynamic memory allocation
char *smash (const char *const words[/* count */], size_t count)
{
// allocate a string on the heap, memory will be freed
  char * rStr = (char *) calloc(128, sizeof(char));
  rStr[0] = '\0';
    
    for (size_t i=0; i<count; i++) {
      const char* word = words[i];
      strncat(rStr, word, strlen(word));
      if (i+1 < count) {
        strncat(rStr, " ", 1);
      }
      
    }
  return rStr;
}
