#include <stdio.h>

int main(void) {
  char freq[36];

  for (int i = 0; i < 36; ++i) {
    freq[i] = 0;
  }

  int c;
  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      ++freq[c - 'a'];
    } else if (c >= '0' && c <= '9') {
      ++freq[c - '0' + 10];
    }
  }

  for (int i = 0; i < 36; ++i) {
    if (i < 26) {
      printf("%c: ", 'a' + i);
    } else if (i >= 26) {
      printf("%c: ", '0' + i - 26);
    }

    for (int j = 0; j < freq[i]; ++j)
      printf("#");

    putchar('\n');
  }

  return 0;
}
