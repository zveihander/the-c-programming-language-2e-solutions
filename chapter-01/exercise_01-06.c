#include <stdio.h>

int main(void) {
  _Bool is_eof = getchar() != EOF;
  printf("is EOF? %d\n", is_eof);
  return 0;
}
