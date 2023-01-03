#include <stdio.h>

int main(void) {
  float a = 420.042f;

  void *b = &a; // Implicit reinterpretation cast
  void *c = (void *) &a; // explicit reinterpretation cast

  void *d = &a; // Implicit promotion -> OK
  int *e = d; // Implicit demotion -> 위험!
  int *f = (int *)d; // explicit demotion

  printf("%p, %f\n", &a, a);
  printf("%p\n", b);
  printf("%p\n", c);

  printf("%p\n", d);
  printf("%p, %d\n", e, *e);
  printf("%p, %d\n", f, *f);

  return (0);
}