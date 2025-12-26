#include <stdio.h>

/* count blanks, tabs, and newlines in input */
int main(void) {
  int c, i;

  i = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n' || c == '\t' || c == ' ')
      ++i;
  printf("%d\n", i);
}
