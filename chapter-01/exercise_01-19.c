#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 // maximum input line length

int my_getline(char line[], int maxline);
void reverse(char line[]);

/* print all input lines and trim trailing blanks, tabs, and delete entirely
 * blank lines */
int main(void) {
  int len;            // current line length
  char line[MAXLINE]; // current input line

  while ((len = my_getline(line, MAXLINE)) > 0) {
    reverse(line);
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

void reverse(char line[]) {
  int length = strlen(line);
  int start = 0;
  int end = length - 1;
  char tmp;

  if (line[end] == '\n') {
    end = end - 1;
  }

  while (start < end) {
    tmp = line[start];
    line[start] = line[end];
    line[end] = tmp;

    ++start;
    --end;
  }
}
