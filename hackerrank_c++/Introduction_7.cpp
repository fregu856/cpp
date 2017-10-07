#include <stdio.h>
#include <cmath>

// In order to access the memory address of a variable, var, we need to prepend
// it with a & sign. E.g., &var returns the memory address of var.

void update(int *a, int *b)
{
  int a_old = *a;
  int b_old = *b;

  *a = a_old + b_old;
  *b = std::abs(a_old - b_old);
}

int main()
{
  int a, b;
  int *pa = &a, *pb = &b;

  scanf("%d %d", &a, &b);
  update(pa, pb);
  printf("%d\n%d", a, b);

  return 0;
}
