#include <stdio.h>

float celsius_to_fahr(int celsius);

int main(void) {
  float celsius, fahr;

  int lower = 0;
  int upper = 300;
  int step = 20;

  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius_to_fahr(celsius);
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}

float celsius_to_fahr(int celsius) { return (9.0 / 5.0) * celsius + 32.0; }
