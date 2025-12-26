#include <stdio.h>

#define MAXLINE 1000 // maximum input line length

int my_getline(char line[], int maxline);
void remove_trailing(char line[], int length);

/* print all input lines and trim trailing blanks, tabs, and delete entirely
 * blank lines */
int main(void) {
  int len;            // current line length
  char line[MAXLINE]; // current input line

  while ((len = my_getline(line, MAXLINE)) > 0) {
    remove_trailing(line, len);
    printf("%s", line);
  }
  return 0;
}

/* getline: read a line into s, return length */
int my_getline(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void remove_trailing(char line[], int length) {
  int i = length - 1;
  if (i < 0)
    return;

  _Bool has_newline = 0;
  if (line[i] == '\n') {
    has_newline = 1;
    i--;
  }

  // Remove the trailing spaces and tabs
  while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
    i--;

  if (i < 0) {
    // This means the line was ALL spaces and tabs
    line[0] = '\0';
    return;
  }

  if (has_newline) {
    line[i + 1] = '\n';
    line[i + 2] = '\0';
  } else {
    line[i + 1] = '\0';
  }
}
