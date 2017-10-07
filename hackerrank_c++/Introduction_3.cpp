#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  int int_var;
  long long_var;
  char char_var;
  float float_var;
  double double_var;

  scanf("%d %ld %c %f %lf", &int_var, &long_var, &char_var, &float_var, &double_var);

  printf("%d\n%ld\n%c\n%f\n%lf", int_var, long_var, char_var, float_var, double_var);

  return 0;
}
