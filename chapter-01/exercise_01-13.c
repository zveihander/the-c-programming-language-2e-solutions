#include <stdio.h>

/* github.com/ohkimur/the-c-programming-language-2nd-edition-solutions
   was very helpful
*/

#define BUFFER 100

/* histogram */
int main(void) {
  int histogram[BUFFER];
  int histogram_length = 0;

  int max_word_count = 0;

  for (int i = 0; i < BUFFER; ++i) {
    histogram[i] = 0;
  }

  int c;
  int word_count_index = 0;
  while ((c = getchar())) {
    if (c == ' ' || c == '\t' || c == '\n' || c == EOF) {
      if (word_count_index > 0) {
        ++histogram[word_count_index - 1];

        if (histogram[word_count_index - 1] > max_word_count) {
          max_word_count = histogram[word_count_index - 1];
        }

        if (histogram_length < word_count_index - 1) {
          histogram_length = word_count_index - 1;
        }

        word_count_index = 0;
      }
      if (c == EOF)
        break;
    } else {
      ++word_count_index;
    }
  }

  histogram[histogram_length + 1] = '$';

  putchar('\n');

  int col_index = 0;
  int line_index = 0;

  while (histogram[col_index] != '$') {
    printf("%3d: \t", col_index + 1);

    for (line_index = 0; line_index < histogram[col_index];
      ++line_index) {
      putchar('#');
    }

    putchar('\n');

    ++col_index;
  }

  return 0;
}
