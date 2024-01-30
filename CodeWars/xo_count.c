#include <stdbool.h>
#include <string.h>

int xo_cnt (const char v) {
  if (v == 'O' || v == 'o') {
    return 1;
  }
  else if (v == 'X' || v == 'x') {
    return -1;
  }
  else { return 0; }
}

bool xo (const char* str)
{
  int cnt = 0;
  
  for (size_t i=0; i<strlen(str); i++) {
    cnt += xo_cnt(str[i]);
  }
  
  return cnt == 0;
}
