#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin >> N;

  int array[N];
  for (int i = 0; i < N; ++i)
  {
    int read_int;
    cin >> read_int;
    array[i] = read_int;
  }

  for (int i = N-1; i >= 0; --i)
  {
    cout << array[i] << " ";
  }

  return 0;
}