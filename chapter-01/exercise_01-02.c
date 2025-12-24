#include <stdio.h>

int main(void) {
  // this produces an "unknown escape sequence" warning
  printf("hello, world\c");
  return 0;
}
