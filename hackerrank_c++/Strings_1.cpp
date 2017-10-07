#include <iostream>
#include <string>

using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;

  int len_a = a.size();
  int len_b = b.size();
  cout << len_a << " " << len_b << endl;

  string ab_concat = a + b;
  cout << ab_concat << endl;

  string a_prime, b_prime;
  a_prime = a;
  b_prime = b;

  a_prime[0] = b[0];
  b_prime[0] = a[0];

  cout << a_prime << " " << b_prime << endl;

  return 0;
}
