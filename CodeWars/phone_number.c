#include <stdint.h>

char *create_phone_number(char phnum[15], const uint8_t digits[10])
{
  int d = 0;
  for (int i=0; i<14; i++) {
    switch (i) {
      case 0:
        phnum[i] = '(';
        break;
      case 4:
        phnum[i] = ')';
        break;
      case 5:
        phnum[i] = ' ';
        break;
      case 9:
        phnum[i] = '-';
        break;
      default:
        /*  IT'S VITAL TO ENSURE YOU ADD '0' CHARACTER TO OFFSET THE
            INTEGER VALUE OF THE uint8_t VALUE TYPE   */
        phnum[i] = (char) digits[d++] + '0';
    }
  }
	phnum[14] = '\0';
    return phnum;
}
