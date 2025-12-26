#include <stdio.h>

int main(void) {
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++i;
      if (i == 1)
        putchar(' ');
    } else {
      putchar(c);
      i = 0;
    }
  }
}
